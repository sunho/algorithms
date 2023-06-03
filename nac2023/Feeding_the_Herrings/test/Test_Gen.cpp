#include <bits/stdc++.h>
#include <random>
using namespace std;
using ll = long long;

int main() {
  int seed;
  cin >> seed;
  mt19937 rng(time(0));
  cout << 1 << "\n";
  int bias =  rng() % 40;
  int a = rng() % 40 + bias, b = a/3 - bias/3;
  cout << a << " " << b << "\n"; 
}
