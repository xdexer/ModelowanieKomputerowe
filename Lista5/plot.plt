set terminal png size 1024,1024 

set output 'montecarlo_errors.png'
set xlabel "Potential Energy"
set ylabel "Kinetic Energy"
plot 'energia.txt' using 0:1 with lines title "Potential", '' using 0:2 with lines title "Kinetic"