#include <stdio.h>
const int N = 1e6 + 2;
int runs[6000005];
double run_rate[6000005];

int main() {
      int n, k;
      scanf("%d %d", &n, &k);
      for (int i = 0; i < n * 6; i++) {
            scanf("%d", &runs[i]);
      }
      int run = 0, ball = 0, total_players = 0;
      for (int i = 0; i < n * 6; i++) {
            if (runs[i] == -1) {
                  double rr = (double)run / (ball + 1);
                  run_rate[total_players++] = rr;
                  run = 0;
                  ball = 0;
            } else {
                  run += runs[i];
                  ++ball;
            }
      }
      if (ball) {
            double rr = (double)run / ball;
            run_rate[total_players++] = rr;
            run = 0;
            ball = 0;
      }

      if (total_players >= k) {
            for (int i = 0; i < k; i++) {
                  printf("%.2lf\n", run_rate[i]);
            }
      } else {
            for (int i = 0; i < total_players; i++) {
                  printf("%.2lf\n", run_rate[i]);
            }
            printf("No more players\n");
      }
}