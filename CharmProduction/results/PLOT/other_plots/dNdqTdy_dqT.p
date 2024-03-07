set xrange [0:20]
set yrange [10**-3:2*10**0]

set lmargin 20
set rmargin 10
set bmargin 7
set grid lw 1

set label 1 '{/:Bold y = 0}' at graph 0.1,0.6 font ',25'
set format y "10^{%T}"
set xtics font ",20"
set ytics font ",20"
set logscale y
set xlabel "{/:Bold pT [Gev/c]}" font ",25" offset 0,-2
set ylabel "{/:Bold dN/dqTdy [c/GeV]}" font ",25" offset -5,3
set title "{/:Bold Charm production yields dN/dqTdy in the 0-5% most central 5.02 Tev Pb+Pb collisions}" font ",28"


plot "~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_qT/dCharmdqTdy_gg_mQ1.5_qSupp0_NSamples1million_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc rgb "blue" lw 2 notitle w l smooth bezier,\


