#To run:

#	. generate_rand_ints.sh #notice the point!

echo "" > list_doubles_huge.txt

MULTIPLIER=10

for i in {1..32000}
do
   #echo $RANDOM >> list_ints_huge.txt
   var1=`echo "scale=5; $RANDOM*$MULTIPLIER/32767" | bc`
   echo $var1 >> list_doubles_huge.txt
done
