#include <stdio.h>
#include <stdbool.h>
int main(void)
{
int var_in = 0;
int var_count = 0;

scanf("%d", &var_in);

while(var_in != 0)
  {
   if ((var_in % 10) == 9) var_count++ ;
   var_in = var_in /10;

  }
var_count == 1 ? printf("YES\n"): printf("NO\n");
}