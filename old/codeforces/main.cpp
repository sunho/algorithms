#include <stdio.h>
int FUNNY_MEMORY[10];
int main() {
  int n;
  scanf("%d", &n);
  FUNNY_MEMORY[n] = 0xdeadbeaf;
  printf("%d", FUNNY_MEMORY[n]);
}
