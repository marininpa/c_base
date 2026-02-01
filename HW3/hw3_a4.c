#include <stdio.h>

int main(void)
{
	int var_a; 
    int var_b;
    int var_c;
    int var_sum;
    long long var_mul;
    scanf("%d %d %d", &var_a, &var_b, &var_c);
    var_sum = var_a + var_b + var_c;
    var_mul = (long long)var_a * var_b * var_c;
	printf("%d+%d+%d=%d\n", var_a, var_b, var_c, var_sum);
    printf("%d*%d*%d=%lld\n", var_a, var_b, var_c, var_mul);
}