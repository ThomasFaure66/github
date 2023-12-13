set xrange [-5:5]
set yrange [10**-1:10**1]

set lmargin 10
set rmargin 10
set bmargin 5
set grid lw 1

set key font ",15"
set key spacing 1
set format y "10^{%T}"
set xtics font ",20"
set ytics font ",20"
set logscale y
set xlabel "y" font ",25" offset 0,0
set ylabel "dN/dy" font ",25" offset 3,3
set title "Charm production yields dN/dy in the 0-5% most central 5.02 Tev Pb+Pb collisions for different values of η/s, with and without quark suppression, compared with the FONLL calculation" font ",15"


plot "~/Bureau/Stage_code/CharmProduction/results/Charm_production_fromFONLL/Charmproduction_FONLL_sym.txt" u 1:($2*0.36*(1165.0*10**-6*26.08*10**3)/10.166) w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.4_qSupp1_NSamples10million_QMin2.8_QMax12_etaovers0.16_alphas0.2703.txt" u 1:2 lc rgb "red"   lw 2 title "η/s = 0.16, alpha-s = 0.2703, Charm mass= 1.4Gev" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.4_qSupp1_NSamples10million_QMin2.8_QMax12_etaovers0.32_alphas0.2703.txt" u 1:2 lc rgb "green" lw 2 title "η/s = 0.32, alpha-s = 0.2703, Charm mass= 1.4Gev" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.6_qSupp1_NSamples10million_QMin3.2_QMax12_etaovers0.16_alphas0.2395.txt" u 1:2 lc rgb "red" dashtype 2 lw 2 title "η/s = 0.16, alpha-s = 0.2395, Charm mass= 1.6Gev" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.6_qSupp1_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395.txt" u 1:2 lc rgb "green" dashtype 2 lw 2 title "η/s = 0.32, alpha-s = 0.2395, Charm mass= 1.6Gev" w l smooth bezier,\

