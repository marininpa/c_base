#include <stdio.h>

int main(void)
{
   int var_a =0;
   int var_b =0;
   scanf("%d %d", &var_a, &var_b);
   (var_a < var_b) ? printf("%d %d\n", var_a, var_b):printf("%d %d\n", var_b, var_a);
}