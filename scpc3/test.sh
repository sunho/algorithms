g++ --std=c++17 ./Rand.cpp -o ./Rand.bin
g++ --std=c++17 -o C_2.bin C_2.cpp || exit
for i in {1..100}
do
  ./Rand.bin <<< "$i" > "./tmp/test$i.in"
  ./C_2.bin < "./tmp/test$i.in" > "./tmp/test$i.ans"
done

g++ --std=c++17 -o program C.cpp || exit
files=$(ls ./tmp/*.in)
for file in $files; do
  name="${file%.*}"
  echo $name
  ./program < "$file" > "$name.out"
  diff "$name.out" "$name.ans" || break
done
