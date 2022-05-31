clear
if [ $# -eq 0 ]
then
		echo "Enter the Directory names" 
			echo "Usage is <$0> <dir1/dir2/dir3/dir4/...>."
				exit

fi
oldifs="$IFS"
IFS=/
for i in $* 
do
		if [ -d $i ]
				then
						    echo "directory $i exists"		
						    	    cd $i
							                   echo "changed to directory $i `pwd`"
									   	else if [ -f  $i ]
												then
															echo "$i is a File"
																	exit
																		else
																					mkdir  $i
																					            	echo "created directory $i "
																									cd  $i
																									                     echo "changed to directory $i `pwd`"
																											       	    fi
																												    	fi
																												done
																												IFS="$oldifs"
																												i

