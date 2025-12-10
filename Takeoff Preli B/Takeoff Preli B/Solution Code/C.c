#include <stdio.h>

int main() {
  int s, k, a;
  scanf("%d %d %d", &s, &k, &a);
  int oppnent_score = s - k;
  if (oppnent_score < 0) {
    oppnent_score = 0;
  }
  if (oppnent_score < a) {
    printf("Shabash Bangladesh\n");
  } else if (oppnent_score == a) {
    printf("Well Played\n");
  } else {
    printf("Heartbreak\n");
  }
  return 0;
}