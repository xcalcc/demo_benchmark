#!/bin/sh


make clean

export CXX="sourceanalyzer -b test c++"
export CC="sourceanalyzer -b test cc"

project=fortify-basic

sourceanalyzer -b $project -clean
sourceanalyzer -b $project touchless make
rm -f $project.fpr $project.html
sourceanalyzer -b $project -scan -f $project.fpr
BIRTReportGenerator -template "Developer Workbook"  -source $project.fpr -format HTML -output $project.html

