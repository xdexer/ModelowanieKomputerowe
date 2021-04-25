set terminal png size 1024,1024 

set output 'results.png'
set xlabel "Time"
set ylabel "Cluster Radius"
plot "results_zad2.txt" with lines