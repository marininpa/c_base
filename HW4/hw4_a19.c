#include <stdio.h>

int main(void)
{

	int a = 0;
  int b = 0;
  int c = 0;
	scanf("%d %d %d", &a, &b, &c);
  (a != 0 && b != 0 && c != 0) ? ((a + b > c && b + c > a && c + a > b) ? printf("YES\n") : printf("NO\n")) : printf("Ошибка ввода\n");
  }
