set logscale y

f(x)=a*x**2+b*x+c
fit f(x) 'out.txt' using 1:4 via a,b,c
set xrange [0:6]
plot f(x), 'out.txt' using 1:4
