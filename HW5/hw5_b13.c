#include <stdio.h>
#include <stdbool.h>
int main(void)
{
int var_in = 0;
int var_count_even= 0;
int var_count_uneven= 0;

scanf("%d", &var_in);

while(var_in != 0)
  {
   ((var_in % 10) % 2) == 0 ? var_count_even++ : var_count_uneven++;
   var_in = var_in / 10;
  }
printf("%d %d\n", var_count_even, var_count_uneven);
}