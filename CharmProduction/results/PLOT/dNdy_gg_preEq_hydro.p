set xrange [-4:5]
set yrange [10**-3:10**1]
set key font ",15"
set key spacing 2
set format y "10^{%T}"
set logscale y
set xlabel "y" font ",15"
set ylabel "dN/dy" font ",15"
set title "Charm production yields dN/dy the 0-5% most central 5.02 Tev Pb+Pb collisions for shear viscosity η/s = 0.16" font ",14"

plot "~/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ1.5_qSupp0_NSamples1000000_QMin3_QMax12_etaovers0.16.txt" u 1:3 lc 1 lw 2 title "Sum" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ1.5_qSupp0_NSamples1000000_QMin3_QMax12_etaovers0.16.txt" u 1:4 lc 2 lw 2 title "Pre-equilibrium" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ1.5_qSupp0_NSamples1000000_QMin3_QMax12_etaovers0.16.txt" u 1:5 lc 7 lw 2 title "Hydrodynamics" w l smooth bezier,\


