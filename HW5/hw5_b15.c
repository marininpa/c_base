#include <stdio.h>
int main(void)
{
int var_in = 0;
int var_count_even = 0;

while(scanf("%d", &var_in) == 1)
{
  if (var_in == 0)
  break;
  else if (var_in % 2 == 0) var_count_even++;

  
}

printf("%d\n", var_count_even);
}