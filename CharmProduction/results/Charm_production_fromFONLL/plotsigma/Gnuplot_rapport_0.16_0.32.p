set xrange [100:400]
set yrange [1.1:1.28]
set key font ",20"
set key bottom right
set key spacing 1


set lmargin 20
set rmargin 20
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "Npart" font ",25" offset 0,-1
set ylabel "(FONLL+Pre-eq)/FONLL" font ",25" offset -5,3
set title "Ration (FONLL+Pre-eq)/FONLL for different values of η/s" font ",16"

plot "~/Bureau/Stage_code/CharmProduction/plotsigma/Rapport_0.16.txt" u 1:2 lc rgb "blue" lw 2 title "η/s = 0.16"w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/plotsigma/Rapport_0.32.txt" u 1:2 lc rgb "red" lw 2 title "η/s = 0.32" w l smooth bezier,\




