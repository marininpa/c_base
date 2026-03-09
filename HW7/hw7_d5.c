#include <stdio.h>

int print_num (int f_num);

int main(void)
{
int l_num = 0;
scanf("%d", &l_num);
l_num == 0 ? printf("%d\n",l_num) : print_num(l_num);
return 0;
}


int print_num (int f_num)
{
if (f_num == 0) return 0;
    print_num(f_num/2);
    printf("%d", f_num%2);
}