
rm Average
make 
./Average $1 2 $2 ../strength mean.dat
gnuplot *.gp
