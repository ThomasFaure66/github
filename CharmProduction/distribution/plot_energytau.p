set xrange [0:0.1]
set yrange [0:2.5]

set lmargin 30
set rmargin 10
set bmargin 10
set grid lw 1

set xtics font ",40" offset 0,-1
set ytics font ",40"

set xlabel "{/:Bold tau (fm/c)}" font ",40" offset 0,-3
set ylabel "{/:Bold Δτ_{prod}/ΔE} " font ",40" offset -13,3



plot "~/Bureau/Stage_code/CharmProduction/distribution/energytau.txt" u 1:2 lc rgb "green" lw 2 notitle w l smooth bezier

