set -e
g++ -DSTRESS -O2 -g --std=c++17 -fsanitize=address,undefined "$1" -o "$1.bin"
