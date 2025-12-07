#include <stdio.h>

long long gcd_ll(long long a, long long b) {
      while (b != 0) {
            long long t = a % b;
            a = b;
            b = t;
      }
      return a;
}

int main() {
      long long r, n;
      scanf("%lld %lld", &r, &n);
      int flag = 0;
      for (long long i = n; i > 0; i--) {
            long long x = i;
            long long sum = 0, b = 0;
            while (sum <= r && x > 0) {
                  if (sum + (x * x) <= r) {
                        sum += (x * x);
                        b += x;
                  } else {
                        long long y = (r - sum) / x;
                        if ((r - sum) % x != 0)
                              sum += (x * x);
                        else
                              sum += (x * y);
                        b += y;
                  }
                  if (sum == r) {
                        flag = 1;
                        break;
                  }
                  x--;
            }
            if (flag) {
                  if (r % b == 0) {
                        printf("%lld\n", r / b);
                  } else {
                        long long g = gcd_ll(r, b);
                        printf("%lld/%lld\n", r / g, b / g);
                  }
                  break;
            }
      }
      if (!flag) printf("-1\n");
      return 0;
}
