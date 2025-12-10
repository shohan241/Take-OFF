#include <math.h>
#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int a[1000000];
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < m; ++i) {
      scanf("%d", &a[i]);
    }

    int xi = -2e9, xj = -2e9, yi = 2e9, yj = 2e9;
    for (int i = 0; i < m; ++i) {
      if (a[i] > xi) {
        xj = xi;
        xi = a[i];
      } else if (a[i] > xj) {
        xj = a[i];
      }

      if (a[i] < yi) {
        yj = yi;
        yi = a[i];
      } else if (a[i] < yj) {
        yj = a[i];
      }
    }
    long long p = 1LL * xi * xj;
    long long q = 1LL * yi * yj;
    long long ans;
    if (p > q)
      ans = p;
    else
      ans = q;
    printf("%lld\n", ans);
  }
  return 0;
}