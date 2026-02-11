#include <stdio.h>
int f_square(int n, int p);

int main(void)
{
int var_n = 0;
int var_p = 0;
scanf("%d %d", &var_n, &var_p);
if ((var_n <= 1000) && (var_p >= 0)) 
f_square(var_n, var_p);
}

int f_square(int var_n, int var_p)
{
int count = 0;
int square = var_n;
if (var_p == 0)
printf("1\n");
else 
{
while (count < var_p-1)
{
square = square * var_n;
count++;
}
printf("%d\n", square);
}
}