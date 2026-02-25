#include <stdio.h>

int print_sum (int f_num);

int main(void)
{
int l_num = 0;
scanf("%d", &l_num);
printf("%d\n", print_sum(l_num));
return 0;
}


int print_sum (int f_num)
{
static int f_sum = 0;
if (f_num > 0)
  {
   f_sum = f_sum + f_num;
   print_sum(f_num-1); 
  }
  return f_sum;
}