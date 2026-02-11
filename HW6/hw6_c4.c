#include <stdio.h>
int f_x(int x);

int main(void)
{
int var_x = 0;
int var_max = 0;

while(scanf("%d", &var_x) == 1)
{
  if (getchar() == '\n')
  break;
  else
  {
  if (f_x(var_x) > var_max)
  var_max = f_x(var_x);
  }
}
printf("%d\n", var_max);


}

int f_x(int x)
{
if (x < 2 && x >= -2)
x = x*x;
else if (x >= 2)
x = x*x + 4*x + 5;
else if (x < -2)
x = 4;
return x;
}