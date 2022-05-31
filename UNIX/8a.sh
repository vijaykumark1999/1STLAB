clear
echo "Enter a username"
read uname
st=`who | tr -s " " | grep -w $uname | cut -d " " -f 4 | head -1`
if [ $st ]
then
	chr=`date +%H`
	cmin=`date +%M`
	lhr=`echo $st | cut -d ":" -f 1`
	lmin=`echo $st | cut -d ":" -f 2`
	hr=`expr $chr - $lhr`
	min=`expr $cmin - $lmin`
	if [ $min -lt 0 ]
	then
		hr=`expr $hr`
		min=`expr $min + 60`
	fi
	echo "$uname is working for $hr hours and $min minutes"
else
	echo "user has not logged in"
fi
