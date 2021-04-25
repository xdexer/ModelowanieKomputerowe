set terminal png size 1024,1024 

set output 'results.png'
set logscale x 2
set logscale y 2
set xlabel "Number of Cells"
set ylabel "Cluster Radius"
plot "results_zad1.txt" with lines

