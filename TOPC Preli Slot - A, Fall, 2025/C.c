#include <stdio.h>

int main() {
      int r, w;
      scanf("%d %d", &r, &w);
      if (r >= 80 && w >= 4) {
            printf("Player of the Match\n");
      } else if (r >= 80 && w < 4) {
            printf("Best Batsman\n");
      } else if (r < 80 && w >= 4) {
            printf("Best Bowler\n");
      } else {
            printf("Participation Award\n");
      }
}