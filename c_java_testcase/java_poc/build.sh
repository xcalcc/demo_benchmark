#!/bin/bash

SHELL_LOCATION=`realpath $0`
CUR_DIR=`dirname ${SHELL_LOCATION}`

if [ "$1" = "clean" ]
then
    find . -name "sootOutput" -exec rm -rf {} \;
    find . -regex ".*\(\.B\|\.class\|\.o\|\.Wb\|\.I\|\.v\|\.t\|\.out\)$" -exec rm -rf {} \;
    exit 0
fi

echo "#### build src code ####"
cd src
javac -g poc/mx_poc/*.java
#cd poc/mx_poc
#javac -g *.java
#cd ../..
find . -name "*.class" -exec xvsa -keep -INLINE:none -xfa -c {} \;

echo "#### build rule ####"
cd $CUR_DIR
cd rule
javac -g io/xc5/RBC_ENGINE.java
javac -g poc/mx_poc/mx_sanitize.java
xvsa -keep -INLINE:none -Wf,-RBC=true -keep -xfa -c poc/mx_poc/ScfpUser.class
#xvsa -INLINE:none -Wf,-RBC=true -xfa -c poc/mx_poc/ScfpUser.class

echo "#### run VSA ####"
cd $CUR_DIR
rm -r vul
mkdir vul
cd vul
find ../src -name "*.B" -exec cp {} . \;
rename 's/\.B/\.o/' *
cp ../rule/ScfpUser.B rule.o
find ../rule -name "*.B" -exec cp {} . \;
xvsa -xfa -json mx_npd.o
xvsa -xfa -json mx_nothrow.o mx_nocatch.o
xvsa -xfa -json mx_sanitize.o ScfpUser.o Constants.o rule.o
