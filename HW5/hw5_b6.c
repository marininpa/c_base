#include <stdio.h>

int main(void)
{
int var_a = 0;
int var_b = 0;
int var_c = 0;
scanf("%d", &var_a);
do
  {
    if (var_a ==0) 
    {
    printf("NO\n");
    break;
    }
    var_b = var_a % 10;
    var_a = var_a / 10;
    var_c = var_a % 10;
   if (var_c == var_b) 
   {
    printf("YES\n");
    break;
   }
} while(1);
}