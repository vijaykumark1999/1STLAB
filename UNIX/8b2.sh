echo "enter user name"
read uname
period=0
until who | grep -w "$uname"
do
	sleep 5
	period=`expr $period + 1`
	if [ $period -gt 1 ]
	then
		echo "$uname has not logged in since 1min"
		exit
	fi
done
echo :$uname has now logged in"
