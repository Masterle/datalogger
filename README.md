# datalogger
datalogger for logfiles, creating selectable output

This project has been started to read out csv files from the heater system of oekofen gmbh in austria.

To reach this I wrote the small download script which can be found in the script folder (downloadLogFiles.sh)
Currently the ip address needs to be corrected in the downloadLogFiles.sh

The second idea was to write a small c++ program which combines all log files from the heater in one single file.
Later one this program shall be able to select the corresponding log channels in a graphical view to see heating curves, etc.
