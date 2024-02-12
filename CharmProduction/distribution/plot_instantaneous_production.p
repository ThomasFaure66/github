set xrange [0:0.1]
set yrange [1:15]

set lmargin 20
set rmargin 10
set bmargin 10
set grid lw 1

set xtics font ",40" offset 0,-1
set ytics font ",40"
set xlabel "{/:Bold tau} (fm/c)" font ",40" offset 0,-3
set ylabel "{/:Bold dN/dydtau} (c/fm)" font ",40" offset -9,3



plot "~/Bureau/Stage_code/CharmProduction/distribution/dCharmdtaudy_gg_mQ1.5_qSupp0_NSamples100000_QMin3_QMax12_tauMax0.2_etaovers0.16.txt" u 1:2 lc rgb "green" lw 2 notitle w l smooth bezier

