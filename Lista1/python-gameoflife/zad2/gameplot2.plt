set terminal png size 1024,1024 

set output 'results.png'
set yrange [0:1000]
set xlabel "Pokolenia"
set ylabel "Ilość żywych komórek"
plot "results0.1.txt" with lines, "results0.3.txt" with lines, "results0.05.txt" with lines, "results0.6.txt" with lines, "results0.8.txt" with lines, "results0.75.txt" with lines, "results0.95.txt" with lines

