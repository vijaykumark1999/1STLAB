clear
if [ $# -gt 0 ]
then
for i in $*
do
if [ -f $i ]
then
echo $i | tr  '[a-z]'  '[A-Z]'
else
echo "$i doesn't exists"
fi
done
else
echo "invalid no: of args"
fi
