
g++ ./test/Test_Gen.cpp -o ./test/Test_Gen.bin
for i in {1..100}
do
  ./test/Test_Gen.bin <<< "$i" > "test$i.in"
  ./test/Brute.bin < "test$i.in" > "test$i.ans"
done
../../run.sh