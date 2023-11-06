set xrange [-4:5]
set yrange [10**-1:10**2]
set key font ",15"
set key spacing 2
set format y "10^{%T}"
set logscale y
set xlabel "y" font ",15"
set ylabel "dN/dy [1/Gev]" font ",15"
set title "Charm production through gluons annihilation for different masses of charm quarks in the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",14"

plot "~/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ0.25_qSupp0_NSamples30000_QMin3_QMax8_etaovers0.16.txt" u 1:3 lc 3 lw 2 title "Charm mass = 0.25 GeV" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ0.5_qSupp0_NSamples30000_QMin3_QMax8_etaovers0.16.txt" u 1:3 lc 4 lw 2 title "Charm mass = 0.5 GeV" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ1.5_qSupp0_NSamples30000_QMin3_QMax8_etaovers0.16.txt" u 1:3 lc 6 lw 2 title "Charm mass = 1.5 GeV" w l smooth bezier,\


