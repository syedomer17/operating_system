echo "Enter the number:"
read n

r=1
r=`expr $n % 2`

if [ $r -eq 1 ]
then
  echo " odd "
else
  echo " even "
fi