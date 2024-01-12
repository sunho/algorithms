set -e
filename=$(cat filename)
g++ -g --std=c++17 -fsanitize=address,undefined brute.cpp -o brute
g++ -g --std=c++17 -fsanitize=address,undefined gen.cpp -o gen
g++ -g --std=c++17 -fsanitize=address,undefined "$filename" -o sol
for ((i = 1; ; ++i)); do
	MallocNanoZone=0 ./gen $i >input_file
	MallocNanoZone=0 ./sol <input_file >myAnswer
	MallocNanoZone=0 ./brute <input_file >correctAnswer
	diff myAnswer correctAnswer >/dev/null || break
	echo "Passed test: " $i
done
echo "WA on the following test:"
cat input_file
echo ""
echo "Your answer is:"
cat myAnswer
echo ""
echo "Correct answer is:"
cat correctAnswer
