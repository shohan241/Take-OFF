#include <stdio.h>

int main() {
      long long int n, t, sum = 0, cnt = 0;
      scanf("%lld %lld", &n, &t);
      long long int arr[n];
      for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
      }
      int ch = -1;
      for (int i = 0; i < n; i++) {
            long long int x = arr[i];
            if (x != -1) {
                  sum += x;
                  cnt++;
                  if (sum >= t && ch == -1) {
                        printf("%lld\n", cnt);
                        ch = 0;
                  }
            }
      }
      if (ch == -1) {
            printf("Mission Failed\n");
      }
      return 0;
}