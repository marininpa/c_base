#include <stdio.h>

int main(void)
{

   unsigned int var_in = 0; 
	unsigned int var_a = 0; 
   unsigned int var_b = 0;
   unsigned int var_c = 0;
   unsigned int var_max = 0;
    
    scanf("%u", &var_in);
    var_a = var_in/100;
    var_b = (var_in/10)%10;
    var_c = var_in%10;
   
    var_max = var_a > var_b ? var_a : var_b;
    var_max = var_max > var_c ? var_max : var_c;
    
    printf("%u\n", var_max);
}