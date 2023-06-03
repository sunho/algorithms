g++ -fsanitize=address --std=c++17 -o program main.cpp || exit
files=$(ls *.txt)
for file in $files; do
  name="${file%.*}"
  echo $name
  ./program < "$file" > "$name.out"
  diff "$name.out" "$name.ans" || break
done