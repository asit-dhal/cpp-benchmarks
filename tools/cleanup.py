import argparse
import pandas as pd

def load_csv_file(file_name):
    df1=pd.read_csv(file_name)
    print(df1)

def process_benchmark(data):


def main():
	parser = argparse.ArgumentParser(description='Cleanup Benchmark reort')
	parser.add_argument('file_name', metavar='N', type=str,
                    help='csv file name')
	args = parser.parse_args()
	file_name = args.file_name
	load_csv_file(file_name)

if __name__ == "__main__":
	main()
