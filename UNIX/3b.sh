clear
echo "Enter the password to lock the terminal"
stty -echo
read p1
stty echo
echo "Enter the password to confirm:"
stty -echo
read p2
stty echo
if [ $p1 = $p2 ]
then
echo "Terminal is Locking"
stty eof ^-
stty susp ^-
stty quit ^-
stty stop ^-
stty kill ^-
stty intr ^-
echo "Re-enter password to unlock"
stty  -echo
read p3
while [ $p3 != $p1 ]
do
stty echo
echo "Wrong password, enter the password Correctly"
stty -echo
read p3
done
stty sane
echo "Terminal Unlocked"
else
stty echo
echo "password mismatch ; confirmation failed"
fi
