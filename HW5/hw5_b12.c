#include <stdio.h>
#include <stdbool.h>
int main(void)
{
int var_in = 0;
int var_tmp = 0;
int var_max = 0;
int var_min = 0;

scanf("%d", &var_in);

  var_min = var_max = var_in % 10;
  var_tmp = var_in / 10;
    while (var_tmp != 0)
    {
    var_max > (var_tmp % 10) ? var_max : (var_max = (var_tmp % 10));
    var_min < (var_tmp % 10) ? var_min : (var_min = (var_tmp % 10));
    var_tmp = var_tmp / 10;
    }
  
printf("%d %d\n", var_min, var_max);
}