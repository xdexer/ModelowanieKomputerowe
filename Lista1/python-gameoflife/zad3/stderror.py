import glob
import matplotlib.pyplot as plt
import numpy as np
import math
file_list = glob.glob("."+"/200/*.txt")
print(file_list)

stddevtab = []
std_errors = []

for num, file_path in enumerate(file_list):
    data_file = open(file_path, "r")
    x_arr = []
    avg_sum = 0.0
    var_sum = 0.0

    for i in data_file:
        x = i.rstrip("\n")
        avg_sum += float(x)
        x_arr.append(x)
    avg_sum /= 1000

    for x in x_arr:
        var_sum += (float(x) - avg_sum)**2
    var_sum /= 1000
    stddev = math.sqrt(var_sum)
    stderror = stddev / math.sqrt(1000)
    std_errors.append(stderror)

#standard errors
print(std_errors)
avg_std_error = 0.0

for i in std_errors:
    avg_std_error += i
avg_std_error /= 100
print("Average standard error: ", avg_std_error)