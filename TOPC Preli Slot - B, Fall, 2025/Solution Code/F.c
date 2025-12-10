#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[100005];
  scanf("%s", s);

  int v[100005];
  int top = 0;
  v[top] = 0;

  int fd = 0;
  int move = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      top++;
      v[top] = fd;
    } else if (s[i] == '+' || s[i] == '-') {
      if (!move)
        s[i] = '-';
      else
        s[i] = '+';
    } else if (s[i] == ')') {
      top--;
    } else {
      fd = 1;
    }
    move = v[top];
  }

  printf("%s\n", s);
  return 0;
}