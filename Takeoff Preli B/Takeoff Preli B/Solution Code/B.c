#include <stdio.h>

int main() {
  int V, R, X;
  scanf("%d %d %d", &V, &R, &X);
  int vip_sell = 3 * X * V;
  int regular_sell = X * R;
  int total = vip_sell + regular_sell;
  printf("%d\n", total);
  return 0;
}