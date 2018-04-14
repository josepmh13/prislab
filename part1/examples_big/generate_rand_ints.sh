#To run:

#	. generate_rand_ints.sh #notice the point!

echo "" > list_ints_huge.txt

for i in {1..32000}
do
   echo $RANDOM >> list_ints_huge.txt
done
