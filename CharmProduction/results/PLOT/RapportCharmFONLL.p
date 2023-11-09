set xrange [-4:5]
set yrange [0:30]
set key font ",20"
set key spacing 1

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "y" font ",25"
set ylabel "Ratio Pre-equilibrium/FONLL (%)" font ",25" offset -3,3
set title "Ratio between charm production during the pre-equilibrium and FONLL in the 0-5% most central 5.02 Tev Pb+Pb collisions for different values of η/s with quark suppression factor" font ",14"

plot "~/Bureau/Stage_code/CharmProduction/results/RapportCharmFONLL_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.32.txt" u 1:2 lc "red" lw 2 title "η/s = 0.32" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/RapportCharmFONLL_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc "blue" lw 2 title "η/s = 0.16" w l smooth bezier,\



