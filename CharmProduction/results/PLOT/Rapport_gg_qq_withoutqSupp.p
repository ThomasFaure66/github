set xrange [-4:5]
set yrange [0:15]
set key font ",15"
set key spacing 2
set xlabel "y" font ",15"
set ylabel "Ratio gluons channel/quarks channel" font ",15"
set title "Ratio between thermal charm production from gluons annihilation and thermal charm production from quark/antiquark annihilation, in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",13"

plot "~/Bureau/Stage_code/CharmProduction/results/RapportggqqwithoutqSupp.txt" u 1:2 lc 1 lw 2 notitle w l smooth bezier,\



