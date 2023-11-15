set xrange [-4:5]
set yrange [10**-1:2*10**1]

set lmargin 10
set rmargin 10
set bmargin 5
set grid lw 1

set key font ",15"
set key spacing 1
set format y "10^{%T}"
set xtics font ",20"
set ytics font ",20"
set logscale y
set xlabel "y" font ",25" offset 0,0
set ylabel "dN/dy" font ",25" offset 3,3
set title "Charm production yields dN/dy in the 0-5% most central 5.02 Tev Pb+Pb collisions for different values of η/s, with and without quark suppression, compared with the FONLL calculation" font ",15"

plot "~/Bureau/Stage_code/CharmProduction/results/sigmagood.txt" u 1:2 lc rgb "green" lw 2 title "FONLL" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_PreEq_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc rgb "red" lw 2 title "η/s=0.16 w/o quark suppression" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_PreEq_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc rgb "red" dashtype 2 lw 2 title "η/s=0.16 w/ quark suppression" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_PreEq_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32.txt" u 1:2 lc rgb "blue" lw 2 title "η/s=0.32 w/o quark suppression" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_PreEq_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.32.txt" u 1:2 lc rgb "blue" dashtype 2 lw 2 title "η/s=0.32 w/ quark suppression" w l smooth bezier



