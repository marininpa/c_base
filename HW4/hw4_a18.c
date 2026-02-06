#include <stdio.h>

int main(void)
{

	int a = 0;
  int b = 0;
	scanf("%d %d", &a, &b);
  if (a > b)
  {
    printf("Above\n");
  }
  else if (a < b)
      {
        printf("Less\n");
      }
  else if (a == b)
      {
        printf("Equal\n");
      }
}
