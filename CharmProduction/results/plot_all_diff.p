set xrange [1.4:5.2]
set logscale y
set yrange [10**-7:10**-2]
set format y "10^{%T}"
set key font ",15"
set key spacing 2

set multiplot layout 4,2 columns
set tmargin 2
set lmargin 5
set rmargin 3

set title "y=-3.17 [-3.29,-3.05]"
plot "dNdQ_for_y.txt" u 1:4 pt 7 lc rgb 'red'  lw 5  w  l smooth bezier title "Sum",\
"dNdQ_for_y.txt" u 1:5 pt 7 lc rgb 'green' lw 5  w l smooth bezier title "Pre-equilibrium",\
"dNdQ_for_y.txt" u 1:6 pt 7 lc rgb 'blue' lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "y=-2.175 [-2.29,-2.06]"
plot "dNdQ_for_y.txt" u 1:9 pt 7 lc rgb 'red' lw 5 title "Sum" w  l smooth bezier,\
"dNdQ_for_y.txt" u 1:10 pt 7 lc rgb 'green' lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_for_y.txt" u 1:11 pt 7 lc rgb 'blue' lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "y=-1.21 [-1.32,-1.1]"
plot "dNdQ_for_y.txt" u 1:14 pt 7 lc rgb 'red' lw 5 title "Sum" w  l smooth bezier,\
"dNdQ_for_y.txt" u 1:15 pt 7 lc rgb 'green' lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_for_y.txt" u 1:16 pt 7 lc rgb 'blue' lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "y=-0.3 [-0.4,-0.2]"
plot "dNdQ_for_y.txt" u 1:19 pt 7 lc rgb 'red' lw 5 title "Sum" w  l smooth bezier,\
"dNdQ_for_y.txt" u 1:20 pt 7 lc rgb 'green' lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_for_y.txt" u 1:21 pt 7 lc rgb 'blue' lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "y=0.565 [0.45,0.68]"
plot "dNdQ_for_y.txt" u 1:24 pt 7 lc rgb 'red' lw 5 title "Sum" w  l smooth bezier,\
"dNdQ_for_y.txt" u 1:25 pt 7 lc rgb 'green' lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_for_y.txt" u 1:26 pt 7 lc rgb 'blue' lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "y=1.495 [1.38,1.61]"
plot "dNdQ_for_y.txt" u 1:29 pt 7 lc rgb 'red' lw 5 title "Sum" w  l smooth bezier,\
"dNdQ_for_y.txt" u 1:30 pt 7 lc rgb 'green' lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_for_y.txt" u 1:31 pt 7 lc rgb 'blue' lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "y=2.475 [2.36,2.59]"
plot "dNdQ_for_y.txt" u 1:34 pt 7 lc rgb 'red' lw 5 title "Sum" w  l smooth bezier,\
"dNdQ_for_y.txt" u 1:35 pt 7 lc rgb 'green' lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_for_y.txt" u 1:36 pt 7 lc rgb 'blue' lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "y=3.47 [3.35,3.59]"
plot "dNdQ_for_y.txt" u 1:39 pt 7 lc rgb 'red' lw 5 title "Sum" w  l smooth bezier,\
"dNdQ_for_y.txt" u 1:40 pt 7 lc rgb 'green' lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_for_y.txt" u 1:41 pt 7 lc rgb 'blue' lw 5 title "Hydrodynamics" w l smooth bezier,\

unset multiplot


