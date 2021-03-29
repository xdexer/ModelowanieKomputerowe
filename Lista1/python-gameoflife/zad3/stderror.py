import glob
import matplotlib.pyplot as plt
import numpy as np
import math
import re

file_list = glob.glob("./*.txt")
print(file_list)

stddevtab = []
std_errors = []

for num, file_path in enumerate(file_list):
    data_file = open(file_path, "r")
    print(file_path)

    regex_num = re.compile(r'\d+').findall(file_path)
    regex_num = int(regex_num[0])
    #print(regex_num)
    
    x_arr = []
    avg_sum = 0.0
    var_sum = 0.0

    for i in data_file:
        x = i.rstrip("\n")
        avg_sum += float(x)
        x_arr.append(x)
    avg_sum /= 100

    for x in x_arr:
        var_sum += (float(x) - avg_sum)**2
    var_sum /= 100
    stddev = math.sqrt(var_sum)
    stderror = stddev / math.sqrt(100)
    #stderror /= regex_num
    std_errors.append([regex_num,stderror])

#standard errors
print(std_errors)
