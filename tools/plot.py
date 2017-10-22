from bokeh.plotting import figure, output_file, show
from bokeh.palettes import Spectral11
import pandas as pd

def load_csv_file(file_name):
	df = pd.read_csv(file_name)
	return df


def plot_benchmark(df):
	numlines=df.benchmark_name.nunique()
	mypalette=Spectral11[0:numlines]
	
	p = figure(
	    tools="pan,box_zoom,reset,save",
	    x_axis_label='iterations', y_axis_label='time'
	)

	
	grouped_dfs = dict(tuple(df.groupby(["benchmark_name"])))
	i = 0
	for key, val in grouped_dfs.iteritems():
		p.line(grouped_dfs[key]["operation_count"], grouped_dfs[key]["cpu_time"], legend=key, line_color=mypalette[i])
		i += 1
	
	#print data
	show(p)

data = load_csv_file("../build/reports/processed/double_benchmark_small.csv")
plot_benchmark(data)
