set xrange [0:0.1]
set yrange [1:2*10**4]

set lmargin 20
set rmargin 10
set bmargin 5
set grid lw 1


set format y "10^{%T}"
set xtics font ",30" offset 0,-1
set ytics font ",30"
set logscale y
set xlabel "{/:Bold tau}" font ",30" offset 0,0
set ylabel "{/:Bold energy density}" font ",30" offset -9,3



plot "~/Bureau/Stage_code/CharmProduction/distribution/0_0.1fmc.txt" u 1:4 lc rgb "green" lw 2 notitle w l smooth bezier

