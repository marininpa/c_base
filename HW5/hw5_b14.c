#include <stdio.h>
#include <string.h>
int main(void)
{
int var_in = 0;
int var_count = 0;

while(scanf("%d", &var_in) == 1)
{
  if (var_in == 0)
  break;
  else
  var_count++;
}

printf("%d\n", var_count);
}