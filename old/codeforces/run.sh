basename "$PWD"
g++ -fsanitize=address --std=c++17 -g -o program *.cpp || exit
files=$(ls *.in)
for file in $files; do
  name="${file%.*}"
  echo "$name running"
  [ -s $file ] || { echo "? skipped "; continue; }
  ./program < "$file" > "/tmp/$name.out" || { echo "!! crashed"; exit; }
  diff -y "/tmp/$name.out" "$name.ans"  || { echo "!! failed (L: output | R: answer)"; exit; }
done