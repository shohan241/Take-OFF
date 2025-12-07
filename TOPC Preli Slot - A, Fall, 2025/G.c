#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ll long long int
#define endl '\n'
#define N 200000 + 7
int pre[N][30];

int main() {
      int n, q;
      scanf("%d", &n);
      scanf("%d", &q);

      char str[N];
      scanf("%s", str);

      memset(pre, 0, sizeof(pre));

      bool free_pos[N];
      for (int i = 0; i <= n; i++) {
            free_pos[i] = false;
      }

      for (int i = 0; i < n; i++) {
            if (str[i] == '.') {
                  free_pos[i] = true;
            } else {
                  pre[i][str[i] - 'a']++;
            }
            for (char c = 'a'; c <= 'z'; c++) {
                  if (i > 0) pre[i][c - 'a'] += pre[i - 1][c - 'a'];
            }
      }

      bool op[30];
      for (int i = 0; i < 30; i++) op[i] = false;

      while (q--) {
            int t;
            scanf("%d", &t);
            char c;

            if (t == 2) {
                  int l, r;
                  scanf("%d %d %c", &l, &r, &c);
                  l--;
                  r--;
                  int ans = 0;
                  for (char i = 'a'; i <= 'z'; i++) {
                        if (i == c) continue;
                        ans += pre[r][i - 'a'];
                        if (l > 0) ans -= pre[l - 1][i - 'a'];
                  }
                  printf("%d\n", ans);
                  continue;
            }

            scanf(" %c", &c);
            if (op[c - 'a'] == true) continue;
            op[c - 'a'] = true;

            int in = 0;
            for (int i = 0; i < n; i++) {
                  while (in < n && !free_pos[in]) in++;
                  if (str[i] == c && in < i) {
                        str[in] = c;
                        str[i] = '.';
                        free_pos[in] = false;
                        free_pos[i] = true;
                  }
            }

            memset(pre, 0, sizeof(pre));
            for (int i = 0; i < n; i++) {
                  if (str[i] != '.') pre[i][str[i] - 'a']++;
                  for (char j = 'a'; j <= 'z'; j++) {
                        if (i > 0) pre[i][j - 'a'] += pre[i - 1][j - 'a'];
                  }
            }
      }

      return 0;
}
