#include <stdio.h>

int print_num (int f_num);

int main(void)
{
int l_num = 0;
scanf("%d", &l_num);
l_num == 0; printf("%d",l_num);print_num(l_num);
return 0;
}


int print_num (int f_num)
{
if (f_num > 0)
  {
    printf("%d ", f_num%10);
    print_num(f_num/10);
  }
  return 0;
}