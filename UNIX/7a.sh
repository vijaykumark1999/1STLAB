
currentTime=$(date +"%H")
echo "Current time" : $currentTime
if [ $currentTime -ge 0 -a $currentTime -le 12 ]
then
echo "Good Morning!"
elif [ $currentTime -ge 12 -a $currentTime -le 16 ]
then
echo "Good Afternoon!"
elif [ $currentTime -ge 16 -a $currentTime -le 18 ]
then
echo "Good Evening!"
else
echo "Good Night!"
fi
