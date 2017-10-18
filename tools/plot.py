from bokeh.plotting import figure, output_file, show
import csv

def load_csv_file(file_name):
	data = []
	f = open(file_name)
	reader = csv.reader(f)
	for row in reader:
		data.append(row)
	return data

def process_data(data):
	header = data.pop(0)
	print header
	# process data is a list of list
	# 0 - name
	# 1 - iterations
	# 2 - real_time
	# 3 - cpu time
	process_data = dict()
	previous_benchmark_name = ""
	for rec in data:
		item = list()
		#name, iterations
		name, _iterations = rec[0].split("/")
		iterations = int(_iterations)
		#real_time,cpu_time,time_unit
		real_time = float(rec[2])
		cpu_time = float(rec[3])
		if previous_benchmark_name != name:
			process_data[name] = list()
			previous_benchmark_name = name

		process_data[name].append([iterations, real_time, cpu_time])

	return process_data


def plot_benchmark(data):
	output_file("log_lines.html")
	min_iteration_val = 20000
	max_iteration_val = 0
	min_real_time_val = 20000
	max_real_time_val = 0
	min_cpu_time_val = 20000
	max_cpu_time_val = 0

	for key, val in data.iteritems():
		min_iteration = val[0][0]
		max_iteration = val[len(val)-1][0]
		min_real_time = val[0][1]
		max_real_time = val[len(val)-1][1]
		min_cpu_time = val[0][0]
		max_cpu_time = val[len(val)-1][2]
		if min_iteration < min_iteration_val: min_iteration_val = min_iteration
		if min_real_time < min_real_time_val: min_real_time_val = min_real_time
		if min_cpu_time < min_cpu_time_val: min_cpu_time_val = min_cpu_time
		if max_iteration > max_iteration_val: max_iteration_val = max_iteration
		if max_real_time > max_real_time_val: max_real_time_val = max_real_time
		if max_cpu_time > max_cpu_time_val: max_cpu_time_val = max_cpu_time

	x_axis = list()
	for key, val in data.iteritems():
		for d in val:
			x_axis.append(d[0])
		break

	bench = dict()
	for key, val in data.iteritems():
		bench[key] = list()
		for d in val:
			bench[key].append(d[1])
		

	p = figure(
	    tools="pan,box_zoom,reset,save",
	    y_axis_type="log", y_range=[min_real_time, max_real_time], title="time",
	    x_axis_label='iterations', y_axis_label='time'
	)

	fill_color = ["red", "green", "blue"]
	line_width = [3, 6, 9]
	i = 0
	# # add some renderers
	for key, val in bench.iteritems():
		print val
		print key
		p.line(x_axis, val, legend=key)
		p.circle(x_axis, val, legend=key, fill_color=fill_color[i], size=line_width[i])
		i += 1
		
	#print data
	show(p)

data = load_csv_file("../build/bin/string_benchmark.csv")
data = process_data(data)
plot_benchmark(data)

# prepare some data
# x = [0.1, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0]
# y0 = [i**2 for i in x]
# y1 = [10**i for i in x]
# y2 = [10**(i**2) for i in x]

# # output to static HTML file
#output_file("log_lines.html")

# # create a new plot
#p = figure(
#    tools="pan,box_zoom,reset,save",
#    y_axis_type="log", y_range=[0.001, 10**11], title="log axis example",
#    x_axis_label='sections', y_axis_label='particles'
# )

# # add some renderers
# p.line(x, x, legend="y=x")
# p.circle(x, x, legend="y=x", fill_color="white", size=8)
# p.line(x, y0, legend="y=x^2", line_width=3)
# p.line(x, y1, legend="y=10^x", line_color="red")
# p.circle(x, y1, legend="y=10^x", fill_color="red", line_color="red", size=6)
# p.line(x, y2, legend="y=10^x^2", line_color="orange", line_dash="4 4")

# # show the results
# show(p)