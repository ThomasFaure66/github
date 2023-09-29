set xrange [1:6]
set yrange [10**-9:10**-2]
set key font ",15"
set key spacing 2
set format y "10^{%T}"
set logscale y
set xlabel "Q"
set ylabel "dN/dQdy"

set multiplot layout 2,2 columns
set tmargin 2
set lmargin 5
set rmargin 3

set title "qT = [0,10]"
plot "dNdQ_qTMin0_qTMax10.txt" u 1:2 pt 7 lc 1 lw 5 title "Sum"w l smooth bezier,\
"dNdQ_qTMin0_qTMax10.txt" u 1:3 pt 7 lc 3 lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_qTMin0_qTMax10.txt" u 1:4 pt 7 lc 4 lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "qT = [0.1,10]"
plot "dNdQ_qTMin0.1_qTMax10.txt" u 1:2 pt 7 lc 1 lw 5 title "Sum"w l smooth bezier,\
"dNdQ_qTMin0.1_qTMax10.txt" u 1:3 pt 7 lc 3 lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_qTMin0.1_qTMax10.txt" u 1:4 pt 7 lc 4 lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "qT = [1,10]"
plot "dNdQ_qTMin1_qTMax10.txt" u 1:2 pt 7 lc 1 lw 5 title "Sum"w l smooth bezier,\
"dNdQ_qTMin1_qTMax10.txt" u 1:3 pt 7 lc 3 lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_qTMin1_qTMax10.txt" u 1:4 pt 7 lc 4 lw 5 title "Hydrodynamics" w l smooth bezier,\

set title "qT = [2,10]"
plot "dNdQ_qTMin2_qTMax10.txt" u 1:2 pt 7 lc 1 lw 5 title "Sum"w l smooth bezier,\
"dNdQ_qTMin2_qTMax10.txt" u 1:3 pt 7 lc 3 lw 5 title "Pre-equilibrium" w l smooth bezier,\
"dNdQ_qTMin2_qTMax10.txt" u 1:4 pt 7 lc 4 lw 5 title "Hydrodynamics" w l smooth bezier,\

