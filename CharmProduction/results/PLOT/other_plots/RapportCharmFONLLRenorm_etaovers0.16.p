set xrange [-5:0]
set yrange [0:35]

set key font ",20"
set key spacing 1
set key right bottom
set key box vertical width -5 height 1 maxcols 1 spacing 1
set key Left
set key reverse

set lmargin 15
set rmargin 10
set bmargin 5
set grid lw 1

set xtics font ",20"
set ytics font ",20"

set xlabel "{/:Bold y}" font ",25"
set ylabel "{/:Bold Ratio (%)}" font ",25" offset -3,3
set title "{/:Bold Ratio between charm production in the pre-equilibrium and charm production due to hard scattering} \n  {/:Bold the 0-5% most central 5.02 Tev Pb+Pb collisions} " font ",23"

plot "~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.4_qSupp0_NSamples10million_QMin2.8_QMax12_etaovers0.16_alphas0.2703.txt" u 1:2 lc "red" lw 2 dashtype 2 title "M_c = 1.4Gev, α_s = 0.2703, w/o quark supp" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.4_qSupp1_NSamples10million_QMin2.8_QMax12_etaovers0.16_alphas0.2703.txt" u 1:2 lc "red"  lw 2 title "w/ quark suppression" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.16_alphas0.2395.txt" u 1:2 lc "blue" lw 2 dashtype 2 title "M_c = 1.6Gev, α_s = 0.2395, w/o quark supp" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Ratio/NSamples10million/Ratio_CharmFONLLRenormalisé/Ratio_CharmFONLLRenorm_mQ1.6_qSupp1_NSamples10million_QMin3.2_QMax12_etaovers0.16_alphas0.2395.txt" u 1:2 lc "blue" lw 2 title "w/ quark suppression" w l smooth bezier,\



