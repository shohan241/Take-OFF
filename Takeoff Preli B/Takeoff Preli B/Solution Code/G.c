#include <stdio.h>

#define MX 1000010

int spf[MX];
int vec[MX];
int primes[32];
int need[32];
int pref[MX][32];

void f() {
  for (int i = 0; i <= MX; i++) spf[i] = i;
  for (int i = 2; i * i <= MX; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= MX; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
}

int doFact(int x) {
  int num = 0;
  while (x != 1) {
    int p = spf[x];
    int found = -1;
    for (int i = 0; i < num; i++) {
      if (primes[i] == p) {
        found = i;
        break;
      }
    }
    if (found == -1) {
      primes[num] = p;
      need[num] = 1;
      num++;
    } else {
      need[found]++;
    }
    x /= p;
  }
  return num;
}

int main() {
  f();
  int n, x;
  scanf("%d %d", &n, &x);

  int num = doFact(x);

  for (int i = 0; i <= n; i++)
    for (int j = 0; j < num; j++)
      pref[i][j] = 0;

  for (int i = 1; i <= n; i++) {
    scanf("%d", &vec[i]);
    for (int j = 0; j < num; j++) {
      pref[i][j] = pref[i - 1][j];
      while (vec[i] % primes[j] == 0) {
        pref[i][j]++;
        vec[i] /= primes[j];
      }
    }
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    int flag = 0;
    for (int i = 0; i < num; i++) {
      if (pref[r][i] - pref[l][i] < need[i]) {
        flag = 1;
        break;
      }
    }
    if (!flag)
      printf("Goal\n");
    else
      printf("Missed\n");
  }

  return 0;
}