set xrange [-4:5]
set yrange [10**4:10**6]
set key font ",15"
set key spacing 2

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set logscale y
set format y "10^{%T}"
set xlabel "y" font ",25"
set ylabel "Ratio charm production/dilepton production" font ",25" offset -3.5,3
set title "Ratio between charm production and dilepton production, in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16 with quark suppression factor" font ",16"

plot "~/Bureau/Stage_code/CharmProduction/results/RapportCharmDilepton_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc 1 lw 2 notitle w l smooth bezier,\



