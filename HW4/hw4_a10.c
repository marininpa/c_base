#include <stdio.h>

int main(void)
{
   int var_a =0;
   int var_b =0;
   int var_c =0;
   int var_d =0;
   int var_e =0;
   int var_min =0;
   int var_max =0;
   int var_sum =0;
   scanf("%d %d %d %d %d", &var_a, &var_b, &var_c, &var_d, &var_e);
   var_min = var_a < var_b ? var_a : var_b;
   var_min = var_min < var_c ? var_min : var_c;
   var_min = var_min < var_d ? var_min : var_d;
   var_min = var_min < var_e ? var_min : var_e;

   var_max = var_a > var_b ? var_a : var_b;
   var_max = var_max > var_c ? var_max : var_c;
   var_max = var_max > var_d ? var_max : var_d;
   var_max = var_max > var_e ? var_max : var_e;

   var_sum = var_min + var_max;
   printf("%d\n", var_sum);
}