set xrange [-5:0]
set yrange [0:35]

set key font ",25"
set key spacing 1

set key right bottom
set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "{/:Bold y}" font ",25"
set ylabel "{/:Bold Ratio (%)}" font ",25" offset -3,3
set title "{/:Bold Ratio between charm production in the pre-equilibrium and charm production due to hard scattering} \n including (full lines) and not including (dashed lines) the quark suppression factor, in 5.02 Tev Pb+Pb collisions (centrality integrated) for η/s=0.32" font ",16"

plot "~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.4_qSupp0_NSamples10million_QMin2.8_QMax12_etaovers0.32_alphas0.2703.txt" u 1:2 lc "red" lw 2 dashtype 2 notitle w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.4_qSupp1_NSamples10million_QMin2.8_QMax12_etaovers0.32_alphas0.2703.txt" u 1:2 lc "red"  lw 2 title "Charm mass = 1.4Gev, alphas = 0.2703" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395.txt" u 1:2 lc "blue" lw 2 dashtype 2 notitle w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.6_qSupp1_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395.txt" u 1:2 lc "blue" lw 2 title "Charm mass = 1.6Gev, alphas = 0.2395" w l smooth bezier,\



