#include <stdio.h>

int main(void)
{
int a = 0;
int n = 1;
scanf("%d", &a);
do
 {
  if (a<10) 
  break;
  a = a/10;
  n++;
 }
 while(n<=3);
 n == 3 ? printf("YES\n") : printf("NO\n");

}