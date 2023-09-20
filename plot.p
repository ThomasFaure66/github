set xrange [1:6]
set logscale y
set yrange [10**-6:10**-2]
set key font ",15"
set key spacing 2
plot "out.txt" u 1:4 pt 7 lc 1 lw 5 title "y=-3.17"w l smooth bezier,\
"out.txt" u 1:7 pt 7 lc 2 lw 5 title "y=-2.175"w l smooth bezier,\
"out.txt" u 1:10 pt 7 lc 3 lw 5 title "y=-1.21"w l smooth bezier,\
"out.txt" u 1:13 pt 7 lc 4 lw 5 title "y=-0.3"w l smooth bezier,\
"out.txt" u 1:16 pt 7 lc 5 lw 5 title "y=0.565"w l smooth bezier,\
"out.txt" u 1:19 pt 7 lc 6 lw 5 title "y=1.495"w l smooth bezier,\
"out.txt" u 1:22 pt 7 lc 7 lw 5 title "y=2.475"w l smooth bezier,\
"out.txt" u 1:25 pt 7 lc 8 lw 5 title "y=3.47"w l smooth bezier

