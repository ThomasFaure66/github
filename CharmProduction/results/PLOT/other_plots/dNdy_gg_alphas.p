set xrange [-5:5]
set yrange [10**-1:10**1]
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
set title "Charm production (gluon scatterings) for different values of alpha-s in the 0-5% most central 5.02 Tev Pb+Pb collisions" font ",14"

plot "~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/dCharmdy_gg_mQ1.5_qSupp0_NSamples1million_QMin3_QMax12_etaovers0.16_alphas0.3552.txt" u 1:3 lc rgb "red" lw 2 title "η/s = 0.16, alpha-s = 0.3552" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/dCharmdy_gg_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.3552.txt" u 1:3 lc rgb "red" dashtype 2 lw 2 title "η/s = 0.32, alpha-s = 0.3552" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/dCharmdy_gg_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.2528.txt" u 1:3 lc rgb "green" lw 2 title "η/s = 0.16, alpha-s = 0.2528" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/dCharmdy_gg_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.2528.txt" u 1:3 lc rgb "green" dashtype 2 lw 2 title "η/s = 0.32, alpha-s = 0.2528" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/dCharmdy_gg_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.1957.txt" u 1:3 lc rgb "blue" lw 2 title "η/s = 0.16, alpha-s = 0.1957" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/dCharmdy_gg_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.1957.txt" u 1:3 lc rgb "blue" dashtype 2 lw 2 title "η/s = 0.32, alpha-s = 0.1957" w l smooth bezier,\


