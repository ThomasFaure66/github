set xrange [-4:5]
set yrange [1:4]
set key font ",15"
set key spacing 2

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "y" font ",25"
set ylabel "Ratio (mass = 1.27 GeV/mass = 1.67 Gev)" font ",25" offset -3,3
set title "Ratio between charm production for a charm mass = 1.27 GeV and a charm mass = 1.67 GeV (gluon scatterings channel), in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",13" offset -2

plot "~/Bureau/Stage_code/CharmProduction/results/Rapportdifferentmasses_gg_mQ1.27_1.67_qSupp0_NSamples5million_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc rgb "blue" lw 2 notitle w l smooth bezier,\




