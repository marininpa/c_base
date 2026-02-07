#include <stdio.h>

int main(void)
{
int var_in = 0;
//printf("Введите число от 1 до 100\n");
scanf("%d",&var_in);
if (var_in <= 100) {
   for (int c = 1;c <= var_in;c++) {
      printf("%d %d %d\n", c, c * c, c * c * c);
   }
   
}
else printf("Введено число больше 100");
}