set xrange [-4:5]
set yrange [20:60]
set key font ",15"
set key spacing 2
set xlabel "y" font ",15"
set ylabel "Ratio gluons channel/quarks channel" font ",15"
set title "Ratio between charm production from gluons annihilation and from quark/antiquark annihilation, in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",13"

plot "~/Bureau/Stage_code/CharmProduction/results/RapportggqqwithqSupp.txt" u 1:2 lc 1 lw 2 notitle w l smooth bezier,\



