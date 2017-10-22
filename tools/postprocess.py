import argparse
import os
import pandas as pd
from bokeh.plotting import figure, output_file, show
from bokeh.palettes import Spectral11
from bokeh.io import export_png
import logging


parser = argparse.ArgumentParser(description='Cleanup Benchmark reort')
parser.add_argument('ip_file', metavar='N', type=str, help='input csv file name')
args = parser.parse_args()
ip_file = args.ip_file
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)
	

def get_operation_type(operation_cnt):
    if operation_cnt <= 1024: return 'small'
    elif 1024 < operation_cnt <= 10024: return 'medium'
    elif 10024 < operation_cnt <= 64000: return 'large'
    else: return 'None'

def cleanup_benchmark(file_name):
	logger.info('processing file: %s', file_name)
	df = pd.read_csv(file_name)
	# remove unwanted columns
	unwanted_columns = ['time_unit', 'bytes_per_second', 'items_per_second',
		'label','error_occurred','error_message', 'iterations']
	for col in unwanted_columns:
		logger.info('dropping column: %s', col)
		df.drop(col, axis=1, inplace=True)

	# split benchmark cplumn name
	benchmark_name_df = df['name'].str.split('/', 1, expand=True).rename(columns={0:'benchmark_name', 1:'operation_count'})
	benchmark_name_df[['operation_count']] = benchmark_name_df[['operation_count']].apply(pd.to_numeric)
	df = df.join(benchmark_name_df)
	df.drop('name', axis=1, inplace=True)	
	df['real_time'] = df['real_time'].apply(lambda x: x / 1000)
	df['cpu_time'] = df['cpu_time'].apply(lambda x: x / 1000)
	df["operation_type"] = df['operation_count'].map(get_operation_type)
	return df


def plot_benchmark(df, filename):
	logger.info('plotting: %s', filename)
	numlines=df.benchmark_name.nunique()
	mypalette=Spectral11[0:numlines]
	plot = figure(
	    x_axis_label='iterations', y_axis_label='time'
	)
	grouped_dfs = dict(tuple(df.groupby(["benchmark_name"])))
	i = 0
	for key, val in grouped_dfs.iteritems():
		plot.line(grouped_dfs[key]["operation_count"], grouped_dfs[key]["cpu_time"], legend=key, line_color=mypalette[i])
		i += 1
	
	export_png(plot, filename=filename)
	#show(plot)

def write_to_csv(df, path=None):
	grouped_dfs = dict(tuple(df.groupby(["operation_type"])))
	path, file_name = os.path.split(ip_file)
	file_name, ext = os.path.splitext(file_name)
	for key, val in grouped_dfs.iteritems():
		processed_csv_file_name = path + os.path.sep + "processed" + os.path.sep + file_name + "_" + key + ext
		processed_png_file_name = path + os.path.sep + "processed" + os.path.sep + file_name + "_" + key + ".png"
		grouped_dfs[key].to_csv(processed_csv_file_name, index = False)
		plot_benchmark(grouped_dfs[key], processed_png_file_name)
		logger.info("exported csv file: %s", processed_csv_file_name)
		logger.info("exported png file: %s", processed_png_file_name)

def main():
	df = cleanup_benchmark(ip_file)
	write_to_csv(df)


if __name__ == "__main__":
	main()
