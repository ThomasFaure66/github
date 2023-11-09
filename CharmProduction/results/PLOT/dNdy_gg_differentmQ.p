set xrange [-4:5]
set yrange [10**-1:10**1]
set key font ",15"
set key spacing 2
set format y "10^{%T}"
set logscale y

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "y" font ",25"
set ylabel "dN/dy" font ",25" offset -3,3
set title "Charm production (gluon scatterings) for different masses of charm quark in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",14"

plot "~/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ1.27_qSupp0_NSamples5million_QMin3_QMax12_etaovers0.16.txt" u 1:3 lc rgb "blue" lw 2 title "Charm mass = 1.27 GeV" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ1.5_qSupp0_NSamples5million_QMin3_QMax12_etaovers0.16.txt" u 1:3 lc rgb "red" lw 2 title "Charm mass = 1.5 GeV" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ1.67_qSupp0_NSamples5million_QMin3_QMax12_etaovers0.16.txt" u 1:3 lc rgb "green" lw 2 title "Charm mass = 1.67 GeV" w l smooth bezier,\


