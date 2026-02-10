#include <stdio.h>

int main(void)
{
int var_a = 0;
int var_summ = 0;
scanf("%d", &var_a);
// считаем сумму чисел
// проверяем, что не = 0
if (var_a != 0) 
{
  while(1)
  {
    if (var_a == 0) break;
    var_summ += var_a % 10;
    var_a = var_a / 10;
  }
}
printf("%d\n", var_summ);

}