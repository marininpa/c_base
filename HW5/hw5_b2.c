#include <stdio.h>

int main(void)
{
int a = 0;
int b = 0;
scanf("%d %d", &a, &b);
if (a <= b)
  {
   for (;a <= b;a++)
   printf("%d ",a*a);
  }

}