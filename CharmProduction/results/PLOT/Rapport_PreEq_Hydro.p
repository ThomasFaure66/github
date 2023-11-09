set xrange [-4:5]
set yrange [0:100]
set key font ",15"
set key spacing 2

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "y" font ",25"
set ylabel "Ratio Pre-equilibrium/Hydrodynamics" font ",25" offset -3,3
set title "Ratio between charm production during pre-equilibrium and during hydrodynamics phase (gluon scatterings channel), in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",13"

plot "~/Bureau/Stage_code/CharmProduction/results/RapportPreEqHydro_gg_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc rgb "blue" lw 2 notitle w l smooth bezier,\




