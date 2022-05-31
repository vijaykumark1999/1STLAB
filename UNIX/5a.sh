#!/bin/bash
if [ $# -ne 1 ]
then
	echo  “enter only one filename as argument”
	exit
fi
if  [ -e $1 ]
then
	time=`ls –ld  $1|tr –s “ “|cut –d “ “ –f  6,7,8`
	echo “modification time of file $1 is $time
else
	echo “the file $1 doesn’t exist”
fi
