if [ $# -eq 0 ]
then
  echo “enter a pattern as argument”
else
  if  ls | grep “$1” > out
  then
     for i in `cat out`
     do
        if [ -f $i ]
        then
            echo –e “contents of $i \n `cat $i`”
           cp $i mydir
         fi
     done
else
  echo “ there are no files matching the pattern”
fi
fi
