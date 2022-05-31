clear
if [ $# -lt 2 ]
then
	echo " Not Enough Arguments"
else
	f1=$1
	shift
	for i in `cat $f1`
	do 
		for j in $*
		do
			count=0
			c=`tr '' '\n' <$j | grep -c $i`
			count=`expr $count + $c`
			echo "$i has occured $count time in $j"
		done
		echo
	done
fi
