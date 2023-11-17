set -e
FILE="$1"
FOLDER="${FILE%%.*}_stress"
FOLDER="${FOLDER//-/}"
FOLDER="${FOLDER// /_}"
mkdir "$FOLDER"
readlink -f "$1" >"$FOLDER/filename"
cd "$FOLDER"
cp "../lib/stress_test/brute.cpp" .
cp "../lib/stress_test/gen.cpp" .
cp "../lib/stress_test/run.sh" .
