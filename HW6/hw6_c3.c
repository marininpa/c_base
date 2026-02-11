#include <stdio.h>
int f_middle(int a, int b);

int main(void)
{
int var_n = 0;
int var_p = 0;
scanf("%d %d", &var_n, &var_p); 
printf("%d\n", f_middle(var_n, var_p));
}

int f_middle(int a, int b)
{
return (a+b)/2;
}