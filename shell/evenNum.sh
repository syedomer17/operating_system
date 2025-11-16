echo -n "Enter the number: "
x=2
read num

while [ $x -le $num ]
do
  echo $x
  x=$(( x + 2 ))
done
