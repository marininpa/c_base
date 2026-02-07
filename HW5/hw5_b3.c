#include <stdio.h>

int main(void)
{
int a = 0;
int b = 0;
int summ = 0;
scanf("%d %d", &a, &b);
if (a <= b)
  {
  for (;a <= b;a++)
  summ +=a*a;  
  }
printf("%d\n",summ);
}