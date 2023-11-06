set xrange [3:8]
set yrange [10**-8:10**2]
set key font ",15"
set key spacing 2
set format y "10^{%T}"
set logscale y
set xlabel "M [Gev]" font ", 15"
set ylabel "dN/dQdy [1/Gev]" font ",15"
set title "Charm production and dilepton production yields dN/dQdy in the 0-5% most central 5.02 Tev Pb+Pb collisions at forward rapidity y = 2 for shear viscosity η/s = 0.16" font ",14"
set grid

plot "~/Bureau/Stage_code/CharmProduction/results/dCharmdQdy_gg_mQ1.5_qSupp0_NSamples100000_QMin3.001_QMax8_y2_etaovers0.16.txt" u 1:2 lc 4 lw 2 title "Charm production from gluons annihilation" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dDileptondQdy_qSupp1_NSamples100000_QMin3_QMax8_y2_etaovers0.16.txt" u 1:3 lc 3 lw 2 title "Dilepton production" w l smooth bezier,\
