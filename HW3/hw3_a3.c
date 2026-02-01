#include <stdio.h>

int main(void)
{
	int var_a; 
    int var_b;
    int var_c;
    int var_sum;
    scanf("%d %d %d", &var_a, &var_b, &var_c);
    var_sum = var_a + var_b + var_c;
	printf("%d+%d+%d=%d", var_a, var_b, var_c, var_sum);
}