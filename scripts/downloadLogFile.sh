#!/usr/bin/bash

###
# downloadLogFile.sh fetches logfiles from pelletronic.
# The structure of the filename is http://<ip-address>/logfiles/pelletronic/touch_YYYYMMDD.csv
# YYYY = Year
# MM = Month
# DD = Day
# Author	Axel Schmidt
# Year		2021

###
# buildFileName contructs the filename based on the prefix touch,
# followed by the iso date and csv
# \param[in] 1 - day which will be filled in the iso date, if negative or 0 calculate pre month
# @return touch_YYYYMMDD.csv
function buildFileName()
{
  # define variables for construction
  filePrefix="touch_"
  if [ $1 -lt 1 ] ; then
    month=$(($(date +"%m") - 1))
    # change to absolute value
    dayToBuild=${1#-}
    if [ $month = 12 ]; then
      year=$(($(date +"%Y") - 1))
      if [ $dayToBuild = 0 ]; then
        dayToBuild=31
      else
        dayToBuild=$((31 - ${dayToBuild#0}))
      fi
    elif [ $month = 1 ] || [ $month = 3 ] || [ $month = 5 ] || [ $month = 8 ] || [ $month = 10 ]; then
      year=$(date +"%Y")
      if [ $dayToBuild = 0 ]; then
        dayToBuild=31
      else
        dayToBuild=$((31 - ${dayToBuild#0}))
      fi
    elif [ $month = 4 ] || [ $month = 6 ] || [ $month = 7 ] || [ $month = 9 ] || [ $month = 11 ]; then
      year=$(date +"%Y")
      if [ $dayToBuild = 0 ]; then
        dayToBuild=30
      else
        dayToBuild=$((30 - ${dayToBuild#0}))
      fi
    else
      # determine leap year
      year=$(date +"%Y")
      if [ $year%4 = 0 ]; then
        if [ $dayToBuild = 0 ]; then
          dayToBuild=29
        else
          dayToBuild=$((29 - ${dayToBuild#0}))
        fi
      else
        if [ $dayToBuild = 0 ]; then
          dayToBuild=28
        else
          dayToBuild=$((28 - ${dayToBuild#0}))
        fi
      fi
    fi
    month=$(printf "%02d" $month)
    yearAndMonth=$(echo $year$month)
  else
    yearAndMonth=$(date +"%Y%m")
    dayToBuild=$1
  fi
  # norm day output to always 2 digits
  dayToBuild=$(printf "%02d" ${dayToBuild#0})
  # build filename
  echo "$filePrefix$yearAndMonth$dayToBuild".csv
}

###
# buildUrl constructs the url for logfile requests
# \param[in] 1 - day which will be used for url construction
# @return url which can be used by wget or other downloaders
function buildUrl()
{
  pelletronicIp="192.168.178.191"
  logFilePath="/logfiles/pelletronic/"
  dayToBuild=$1
  echo "http://"$pelletronicIp$logFilePath$(buildFileName $dayToBuild)
}

# go to log folder
cd /home/pi/pelletronic-logs

# get day
today=$(date +"%d")

echo "Download only if not already done."
# get the last 4 days (not today)
for day in {1..4}
do
  printDate=$((${today#0} - ${day#0}))
  # only fetch file if not already fetched
  if [ ! -f "$(buildFileName $printDate)" ]; then
    echo "Download log file for "$(buildUrl $printDate)
    wget $(buildUrl $printDate)
  else
    echo "No Download for "$(buildUrl $printDate)" file already exists"
  fi
done
echo "download finished"
