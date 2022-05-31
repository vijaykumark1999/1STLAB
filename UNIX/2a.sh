clear
if [ $# -eq 2 ]
then
x=`ls -ld $1 | cut -c 2-10`
y=`ls -ld $2 | cut -c 2-10`

if [ $x = $y ]
then
	echo "Permissions are equal"
	echo "Common File permissions of $1 and $2 are: "
	echo $x
else
	echo "Permissions are not equal"
	echo "Permissions of $1 are: "
	echo $x
	echo "Permissions of $2 are : "
	echo $y
fi
else
  echo "enter two filenames as arguments"
fi
