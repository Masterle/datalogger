set title "Datenausgabe Oekofen Ofen"
set decimalsign ","
set xlabel "Datum Uhrzeit"
set xdata time
set timefmt '%d.%m.%Y\t%H:%M:%S'
set xrange ["23.10.2021	00:00:00":"24.10.2021	00:00:00"]
plot "logfile.csv" using 1:5 with points
