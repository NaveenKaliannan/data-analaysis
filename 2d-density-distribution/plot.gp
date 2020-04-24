reset


set xrange [-25:-1]
set yrange [-25:-1]

set dgrid3d 100,100
set cntrparam level incremental 0,1,100
set table "contour.txt"
splot "mean.dat" using 1:2:3 notitle
unset table

unset contour
set surface
set table "dgrid.txt"
splot "mean.dat" using 1:2:3 notitle
unset table

reset
set pm3d map
unset key
set palette rgb 33,13,10
#set palette defined (0 '#352a87', 1 '#0363e1',2 '#1485d4', 3 '#06a7c6', 4 '#38b99e', 5 '#92bf73', 6 '#d9ba56', 7 '#fcce2e', 8 '#f9fb0e')
set autoscale fix
set grid

splot 'dgrid.txt' w pm3d##, 'contour.txt' w l lc rgb "black"

set terminal png enhanced
set terminal postscript eps enhanced
set term postscript enhanced color
##set cblabel "Temperature"
set xlabel "2^{nd} strongest  {/Symbol D}E_{C->N}(t) in KJ/mol" font 'Arial,6'
set ylabel "1^{st} strongest  {/Symbol D}E_{C->N}(t) in KJ/mol" font 'Arial,6'
set encoding utf8 
set terminal postscript enhanced 
set term pdfcairo size 3.5,3 enhanced color \
    font 'Arial,8'  linewidth 0.2
set terminal pdfcairo enhanced size 2.5in,2.5in
set output 'contour.pdf'
replot
