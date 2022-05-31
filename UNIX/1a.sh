if [ $# -eq 1 ]
then
  if [ -d $1 ]
  then
         echo "$1 is a valid directory"
         a=` ls –lR $1 | grep "^-" | sort –n –k 5 –t " " | tail -1`
         fname=`echo $a | cut –f 9 –d " "`
         fsize=`echo $a | cut –f 5 –d " "`
         printf "\n $fname is the lengthiest file with size $fsize bytes in directory $1\n"
else
        echo "$1 is not a directory"
  fi
else
      echo "enter a directory name as argument"
fi	

