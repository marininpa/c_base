#include <stdio.h>

int main(void)
{
   int var_a =0;
   int var_b =0;
   int var_c =0;
   int var_max =0;
   scanf("%d %d %d", &var_a, &var_b, &var_c);
   var_max = var_a > var_b ? var_a : var_b;
   var_max = var_max > var_c ? var_max : var_c;
   printf("%d\n", var_max);
}