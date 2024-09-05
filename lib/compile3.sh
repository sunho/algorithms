set -e
g++ -DSTRESS -O3 --std=c++17 "$1" -o "$1.bin"
