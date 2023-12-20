set xrange [-5:0]
set yrange [0:35]

set key font ",25"
set key spacing 1
set key bottom right

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "y" font ",25"
set ylabel "Ratio (%)" font ",25" offset -3,3
set title "{/:Bold Ratio between charm production in the pre-equilibrium and charm production due to hard scattering} \n including (full lines) and not including (dashed lines) the quark suppression factor, in 5.02 Tev Pb+Pb collisions (centrality integrated) for different values of η/s" font ",16"

plot "~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.3.txt" u 1:2 lc "red" lw 2 dashtype 2 notitle w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.3.txt" u 1:2 lc "red" lw 2 title "η/s=0.16" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.3.txt" u 1:2 lc "blue" lw 2 dashtype 2 notitle w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.3.txt" u 1:2 lc "blue" lw 2 title "η/s=0.32" w l smooth bezier,\



