#include <stdio.h>
#include <stdbool.h>
int main(void)
{
int var_in = 0;
int var_chek = 0;
int var_count = 0;

scanf("%d", &var_in);

while(var_in != 0)
  {
   var_chek = var_in % 10;
   var_in = var_in /10;
   if (var_in == 0) break;
   if (var_chek <= (var_in % 10)) var_count++ ;
   }
var_count == 0 ? printf("YES\n"): printf("NO\n");
}