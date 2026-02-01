#include <stdio.h>

int main(void)
{
	int var_a = 0; 
    int var_b = 0;
    int var_c = 0;
    float var_ssum = 0;
    int var_count = 0;

    var_count = scanf("%d %d %d", &var_a, &var_b, &var_c);
    var_ssum = (float)(var_a + var_b + var_c)/var_count;
    printf("%.2f\n", var_ssum);
}