set xrange [-4:5]
set yrange [0:30]
set key font ",15"
set key spacing 2
set xlabel "y" font ",15"
set ylabel "Ratio FONLL/gluons channel (%)" font ",15"
set title "Ratio between FONLL and charm production through gluons annihilation in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",14"

plot "~/Bureau/Stage_code/CharmProduction/results/RapportggFONLLPourcent.txt" u 1:2 lc 1 lw 2 notitle w l smooth bezier,\



