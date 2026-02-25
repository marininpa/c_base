#include <stdio.h>

int print_num (int f_num);

int main(void)
{
int l_num = 0;
scanf("%d", &l_num);
print_num(l_num);
return 0;
}


int print_num (int f_num)
{
static int f_tmp = 1;
if (f_num > 0)
  {
    printf("%d ", f_tmp++);
    print_num(f_num-1);
  }
  return 0;
}