set xrange [-4:5]
set yrange [10**-1:10**1]

set key font ",15"
set key spacing 1
set format y "10^{%T}"
set logscale y
set xlabel "y" font ",15"
set ylabel "dN/dy" font ",15"
set title "Charm production yields dN/dy in the 0-5% most central 5.02 Tev Pb+Pb collisions for different values of η/s, with and without quark suprression factor" font ",14"

plot "~/Bureau/Stage_code/CharmProduction/results/dCharmdy_PreEq_mQ1.5_qSupp0_NSamples1000000_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc 3 lw 3 title "eta/s = 0.16 w/o quark supp" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_PreEq_mQ1.5_qSupp1_NSamples1000000_QMin3_QMax12_etaovers0.16.txt" u 1:2 lc 3 lw 3 dashtype 2 title "eta/s = 0.16 w/ quark supp" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_PreEq_mQ1.5_qSupp0_NSamples1000000_QMin3_QMax12_etaovers0.32.txt" u 1:2 lc 10 lw 3 title "eta/s = 0.32 w/o quark supp" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/dCharmdy_PreEq_mQ1.5_qSupp1_NSamples1000000_QMin3_QMax12_etaovers0.32.txt" u 1:2 lc 10 lw 3 dashtype 2 title "eta/s = 0.32 w/ quark supp" w l smooth bezier,\




