set terminal png size 1024,1024 

set output 'montecarlo_errors.png'
set xlabel "Number of Points"
set ylabel "Integral Error"
plot "wynik_montecarlo.txt" every 10 with lines 