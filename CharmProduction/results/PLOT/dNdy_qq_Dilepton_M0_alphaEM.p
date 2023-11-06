set xrange [-4:5]
set yrange [10**-6:10**-3]
set key font ",15"
set key spacing 2
set format y "10^{%T}"
set logscale y
set xlabel "y" font ",15"
set ylabel "dN/dy" font ",15"
set title "Production yields dN/dy of charm quarks and dileptons in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",14"

plot "~/Bureau/Stage_code/CharmProduction/results/dCharmdy_qq_mQ0_alphaEM_qSupp0_NSamples300000_QMin3_QMax12_etaovers0.16.txt" u 1:3 lc 1 lw 2 title "Charm production through quark annihilation with charm mass = 0 and alpha = alphaEM" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dDileptondy_qSupp1_NSamples300000_QMin3_QMax12_etaovers0.16.txt" u 1:3 lc 2 lw 2 title "dilepton production including the quark suppresion factor"w l smooth bezier,\



