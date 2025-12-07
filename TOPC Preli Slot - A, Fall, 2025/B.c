#include <stdio.h>

int main() {
      int x;
      scanf("%d", &x);

      printf("%d overs %d balls\n", x / 7, x % 7);

      return 0;
}