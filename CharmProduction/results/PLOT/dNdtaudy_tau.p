set xrange [0:1]
set yrange [0:2]

set lmargin 20
set rmargin 10
set bmargin 7
set grid lw 1

set label 1 '{/:Bold y = 0}' at graph 0.05,0.9 font ',25'
set key font ",30"
set key spacing 1
set key bottom right
set key box vertical width 0 height 1 maxcols 1 spacing 1
set key Left
set key reverse

set xtics font ",20"
set ytics font ",20"
set xlabel "{/:Bold tau [fm/c]}" font ",25" offset 0,-2
set ylabel "{/:Bold dN/dtaudy [c/fm]}" font ",25" offset -5,3
set title "{/:Bold Charm production yields dN/dtaudy in the 0-5% most central 5.02 Tev Pb+Pb collisions}" font ",28"


plot "~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_tau/dCharmdtaudy_gg_mQ1.5_qSupp0_NSamples1million_QMin3_QMax12_tauMax1_etaovers0.16.txt" u 1:2 lc rgb "blue" lw 2 title "η/s=0.16" w l smooth bezier,\
"~/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_tau/dCharmdtaudy_gg_mQ1.5_qSupp0_NSamples1million_QMin3_QMax12_tauMax1_etaovers0.32.txt" u 1:2 lc rgb "red" lw 2 title "η/s=0.32" w l smooth bezier,\



