set xrange [-5:0]
set yrange [10**-1:2*10**1]

set lmargin 10
set rmargin 10
set bmargin 5
set grid lw 1

set key font ",25"
set key spacing 1
set key bottom right
set format y "10^{%T}"
set xtics font ",20"
set ytics font ",20"
set logscale y
set xlabel "{/:Bold y}" font ",25" offset 0,0
set ylabel "{/:Bold dN/dy}" font ",25" offset 3,3
set title "{/:Bold Charm production yields dN/dy in the 0-5% most central 5.02 Tev Pb+Pb collisions for η/s=0.32, including (full lines) and not including (dashed lines) the quark suppression factor}" font ",13"


plot "~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.4_qSupp0_NSamples10million_QMin2.8_QMax12_etaovers0.32_alphas0.2703.txt" u 1:3 lc rgb "green" lw 2 title "Charm production due to hard scattering" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.4_qSupp0_NSamples10million_QMin2.8_QMax12_etaovers0.32_alphas0.2703.txt" u 1:2 lc rgb "red" dashtype 2 lw 2 notitle w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.4_qSupp1_NSamples10million_QMin2.8_QMax12_etaovers0.32_alphas0.2703.txt" u 1:2 lc rgb "red" lw 2 title "Pre-equilibirum production with alpha-s = 0.2703 and Charm mass= 1.4Gev" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395.txt" u 1:2 lc rgb "blue" dashtype 2 lw 2 notitle  w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.6_qSupp1_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395.txt" u 1:2 lc rgb "blue" lw 2 title "Pre-equilibirum production with alpha-s = 0.2395 and Charm mass= 1.6Gev" w l smooth bezier,\

