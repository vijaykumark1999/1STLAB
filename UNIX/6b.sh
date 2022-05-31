echo “enter a directory name”
read d
if [ -d $d ]
then
   for i in `ls $d`
   do
      if [ -f $d/$i –a `expr “$i” : “.*”`  -ge 10 ]
      then
         echo $i
      fi
  done
else
   echo “$d is not a directory”
fi

