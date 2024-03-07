set xrange [-4:5]
set yrange [10**-6:10**-3]
set key font ",15"
set key spacing 2
set format y "10^{%T}"
set logscale y

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"
 
set xlabel "y" font ",25"
set ylabel "dN/dy" font ",25" offset -3,3
set title "Production yields dN/dy of charm quarks and dileptons in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",14"

plot "~/Bureau/Stage_code/CharmProduction/results/dCharmdy_qq_mQ0_alphaEM_qSupp0_NSamples300000_QMin3_QMax12_etaovers0.16.txt" u 1:3 lc rgb "blue" lw 2 title "Charm production through quark annihilation with charm mass = 0 and alpha = alphaEM" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dDileptondy_qSupp1_NSamples300000_QMin3_QMax12_etaovers0.16.txt" u 1:3 lc rgb "red" lw 2 title "dilepton production including the quark suppresion factor"w l smooth bezier,\



