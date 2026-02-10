#include <stdio.h>
#include <stdbool.h>
int main(void)
{
int var_a = 0;
int var_b = 0;
int var_c = 0;
bool flag = true;

flag = false;
scanf("%d", &var_a);

while(var_a != 0)
  {
    var_b = var_a % 10;
    var_c = var_a = var_a / 10;
    while (var_c != 0)
    {
     if (var_b == (var_c % 10)) 
     flag = true;
     var_c = var_c / 10;
    }
}
flag == true ? printf("YES\n"): printf("NO\n");
}