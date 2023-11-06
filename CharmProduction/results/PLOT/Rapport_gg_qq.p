set xrange [-4:5]
set yrange [0:60]
set key font ",15"
set key spacing 2
set xlabel "y" font ",15"
set ylabel "Ratio gluons channel/quarks channel" font ",15"
set title "Ratio between charm production from gluons annihilation and charm production from quark/antiquark annihilation, in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",13"

plot "~/Bureau/Stage_code/CharmProduction/results/RapportggqqwithqSupp.txt" u 1:2 lc 1 lw 2 title "with quark suppression factor" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/RapportggqqwithoutqSupp.txt" u 1:2 lc 7 lw 2 title "without quark suppression factor" w l smooth bezier,\



