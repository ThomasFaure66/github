set xrange [-4:5]
set yrange [20000:75000]
set key font ",15"
set key spacing 2
set xlabel "y" font ",15"
set ylabel "Ratio charm production/dilepton production" font ",15"
set title "Ratio between charm production from gluons annihilation and dilepton production through quark-antiquark annihilation, in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",13"

plot "~/Bureau/Stage_code/CharmProduction/results/Rapport_charmdilepton.txt" u 1:2 lc 1 lw 2 notitle w l smooth bezier,\



