set xrange [0:0.2]
set yrange [1:5*10**3]

set lmargin 30
set rmargin 10
set bmargin 10
set grid lw 1


set format y "10^{%T}"
set xtics font ",40" offset 0,-1
set ytics font ",40"
set logscale y
set xlabel "{/:Bold tau (fm/c)}" font ",40" offset 0,-3
set ylabel "{/:Bold energy density}" font ",40" offset -15,3



plot "~/Bureau/Stage_code/CharmProduction/results/Distribution_Temperature_Energy_as_a_function_of_tau/DTE_etaovers0.16_alphas0.3_qSupp0_Q4_qT5_NSamples1million.txt" u 1:5 lc rgb "green" lw 2 notitle w l smooth bezier

