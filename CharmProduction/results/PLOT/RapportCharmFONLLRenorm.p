set xrange [-5:5]
set yrange [0:15]

set key font ",20"
set key spacing 1

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "y" font ",25"
set ylabel "Ratio (%)" font ",25" offset -3,3
set title "{/:Bold Ratio between charm production in the pre-equilibrium (from gluon scattering) and charm production from hard scatterings} \n in 5.02 Tev Pb+Pb collisions (centrality integrated) for η/s=0.16, normalized by the experimental value dσcc/dy =1165 μb for pp collisions" font ",16"

plot "~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples1million/Ratio_CharmFONLLRenorm_gg_mQ1.4_qSupp0_NSamples1million_QMin2.8_QMax12_etaovers0.16_alphas0.2703_centralityaveraged.txt" u 1:2 lc "red" lw 2 title "Charm mass = 1.4Gev, alphas = 0.2703" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples1million/Ratio_CharmFONLLRenorm_gg_mQ1.5_qSupp0_NSamples1million_QMin3_QMax12_etaovers0.16_alphas0.2528_centralityaveraged.txt" u 1:2 lc "green" lw 2 title "Charm mass = 1.5Gev, alphas = 0.2528" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples1million/Ratio_CharmFONLLRenorm_gg_mQ1.6_qSupp0_NSamples1million_QMin3.2_QMax12_etaovers0.16_alphas0.2395_centralityaveraged.txt" u 1:2 lc "blue" lw 2 title "Charm mass = 1.6Gev, alphas = 0.2395" w l smooth bezier,\



