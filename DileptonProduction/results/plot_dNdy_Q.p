set xrange [-4:5]
set yrange [10**-9:10**-2]
set key font ",15"
set key spacing 2
set format y "10^{%T}"
set logscale y
set xlabel "y"
set ylabel "dN/dy"


plot "dNdQ_for_Q.txt" u 1:5 pt 7 lc 1 lw 5 title "Q=[1.5,2.5]"w l smooth bezier,\
"dNdQ_for_Q.txt" u 1:10 pt 7 lc 2 lw 5 title "Q=[2.5,3.5]"w l smooth bezier,\
"dNdQ_for_Q.txt" u 1:15 pt 7 lc 3 lw 5 title "Q=[3.5,4.5]"w l smooth bezier,\
"dNdQ_for_Q.txt" u 1:20 pt 7 lc 4 lw 5 title "Q=[4.5,5.5]"w l smooth bezier,\



