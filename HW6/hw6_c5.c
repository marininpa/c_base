#include <stdio.h>
int f_summ(int n);

int main(void)
{
int var_n = 0;
scanf("%d", &var_n);
printf("%d\n", f_summ(var_n));

return 0;
}

int f_summ(int n)
{
int var_count = 1;
int var_summ = 1;
while (var_count < n)
{
var_summ += ++var_count;
}
return var_summ;
}