clear
if [ $# -eq 0 ]
then
echo "No arguments. Enter some valid login-names as arguments"
else
for x in $*
do
if grep "^$x:" /etc/passwd > temp
then
y=`cut -d ":" -f  6  temp`
echo "Login name= " $x
echo "Home directory= " $y
else
echo "Login name does not exist"
fi
done
fi
