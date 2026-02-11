#include <stdio.h>
#include <stdbool.h>
int main(void)
{
int var_in = 0;
int var_revers = 0;

scanf("%d", &var_in);

while(var_in != 0)
  {
   var_revers = (var_revers * 10) + (var_in % 10);
   var_in = var_in / 10;
  }
printf("%d\n", var_revers);
}