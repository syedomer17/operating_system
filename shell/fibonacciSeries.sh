echo "Enter the no. of number in the series:"
read n
a=0
b=1
d=2

echo "$a"
echo "$b"

while [ $d -lt $n ]
do
c=`expr $a + $b`
echo "$c"
a=$b
b=$c   
d=`expr $d + 1`
done