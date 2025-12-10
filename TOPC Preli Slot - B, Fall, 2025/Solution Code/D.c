#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  int acnt = 0, bcnt = 0;

  for (int i = 0; i < n; ++i) {
    if (((i + 1) % 2 == 1) && (arr[i] % 2 == 1))
      acnt++;
    else if (((i + 1) % 2 == 0) && (arr[i] % 2 == 0))
      bcnt++;
  }

  if (acnt > bcnt) {
    printf("Anda\n");
  } else if (acnt < bcnt) {
    printf("Dim\n");
  } else {
    printf("Draw\n");
  }

  return 0;
}