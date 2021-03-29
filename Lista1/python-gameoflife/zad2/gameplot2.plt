set terminal png size 1024,1024 

set output 'results.png'
set yrange [0:1]
set xlabel "Pokolenia"
set ylabel "Ilość żywych komórek"
plot "results0.1.txt" u 1:($2/(100*100)) with lines, "results0.3.txt" u 1:($2/(100*100)) with lines, "results0.05.txt" u 1:($2/(100*100)) with lines, "results0.6.txt" u 1:($2/(100*100)) with lines, "results0.8.txt" u 1:($2/(100*100)) with lines, "results0.75.txt" u 1:($2/(100*100)) with lines, "results0.95.txt" u 1:($2/(100*100)) with lines

