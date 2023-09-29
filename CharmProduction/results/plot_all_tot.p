set xrange [1:6]
set logscale y
set yrange [10**-6:10**-2]
set key font ",15"
set key spacing 2

plot "dNdQ_for_y.txt" u 1:4 pt 7 lc 1 lw 5 title "y=-3.17 [-3.29,-3.05]"w l smooth bezier,\
"dNdQ_for_y.txt" u 1:9 pt 7 lc 2 lw 5 title "y=-2.175 [-2.29,-2.06]"w l smooth bezier,\
"dNdQ_for_y.txt" u 1:14 pt 7 lc 3 lw 5 title "y=-1.21 [-1.32,-1.1]"w l smooth bezier,\
"dNdQ_for_y.txt" u 1:19 pt 7 lc 4 lw 5 title "y=-0.3 [-0.4,-0.2]"w l smooth bezier,\
"dNdQ_for_y.txt" u 1:24 pt 7 lc 5 lw 5 title "y=0.565 [0.45,0.68]"w l smooth bezier,\
"dNdQ_for_y.txt" u 1:29 pt 7 lc 6 lw 5 title "y=1.495 [1.38,1.61]"w l smooth bezier,\
"dNdQ_for_y.txt" u 1:34 pt 7 lc 7 lw 5 title "y=2.475 [2.36,2.59]"w l smooth bezier,\
"dNdQ_for_y.txt" u 1:39 pt 7 lc 8 lw 5 title "y=3.47 [3.35,3.59]"w l smooth bezier

