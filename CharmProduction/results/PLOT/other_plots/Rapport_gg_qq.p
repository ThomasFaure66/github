set xrange [-4:5]
set yrange [0:80]
set key font ",15"
set key spacing 2

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "y" font ",25"
set ylabel "Ratio gluons channel/quarks channel" font ",25" offset -3,3
set title "Ratio between charm production from gluon scattering and charm production from quark/antiquark annihilation, in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",13"

plot "~/Bureau/Stage_code/CharmProduction/results/Rapportggqq_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc 1 lw 2 title "with quark suppression factor" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Rapportggqq_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc 7 lw 2 title "without quark suppression factor" w l smooth bezier,\



