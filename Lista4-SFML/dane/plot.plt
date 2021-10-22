set terminal png size 1600, 900

set output 'result.png'
set title 'Result'
plot 'wynikp1_020_p2_002.txt' using 0:2 with lines title "I", '' using 0:3 with lines title "S", '' using 0:4 with lines title "R"