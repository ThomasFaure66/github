set xrange [-5:0]
set yrange [10**-1:2*10**1]

set lmargin 30
set rmargin 10
set bmargin 10
set grid lw 1

set key font ",30"
set key spacing 1
set key bottom right
set key box vertical width -5 height 1
set key Left
set key reverse

set format y "10^{%T}"
set xtics font ",40" offset 0,-1
set ytics font ",40"
set logscale y
set xlabel "{/:Bold y}" font ",40" offset 0,-3
set ylabel "{/:Bold dN/dy}" font ",40" offset -13,3


plot "~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.4_qSupp0_NSamples10million_QMin2.8_QMax12_etaovers0.16_alphas0.2703.txt" u 1:3 lc rgb "green" lw 2 title "Production from hard scattering" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.3.txt" u 1:2 lc rgb "red" dashtype 2 lw 2 title "η/s=0.16 w/o quark supp" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.3.txt" u 1:2 lc rgb "red" lw 2 title "w/ quark suppression" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.3.txt" u 1:2 lc rgb "blue" dashtype 2 lw 2 title "η/s=0.32 w/o quark supp"  w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_y/NSamples10million/PreEq/dCharmdy_PreEq_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.3.txt" u 1:2 lc rgb "blue" lw 2 title "w/ quark suppression" w l smooth bezier,\

