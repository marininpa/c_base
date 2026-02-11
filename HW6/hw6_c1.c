#include <stdio.h>
int f_modul(int a);

int main(void)
{
int var_in = 0;
scanf("%d", &var_in);
f_modul(var_in);

}

int f_modul(int var_a)
{
printf("%d\n", (var_a >= 0) ? var_a : -var_a);
}