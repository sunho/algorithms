set -e
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
FILE="$1"
FOLDER="${FILE%%.*}_stress"
FOLDER="${FOLDER//./_}"
FOLDER="${FOLDER//-/}"
FOLDER="${FOLDER// /_}"
mkdir "$FOLDER"
readlink -f "$1" >"$FOLDER/filename"
cd "$FOLDER"
cp "$SCRIPT_DIR/brute.cpp" .
cp "$SCRIPT_DIR/gen.cpp" .
cp "$SCRIPT_DIR/run.sh" .
