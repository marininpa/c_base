#include <stdio.h>

int main(void)
{
    unsigned int var_in = 0; 
	unsigned int var_s = 0; 
    unsigned int var_d = 0;
    unsigned int var_e = 0;
    unsigned int var_sum = 0;
    
    scanf("%u", &var_in);
    var_s = var_in/100;
    var_d = (var_in/10)%10;
    var_e = var_in%10;
    var_sum = var_s + var_d + var_e;
    printf("%u\n", var_sum);
}