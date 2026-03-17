#include <stdio.h>

int in_arr(char *arr);
void print_digit(char s[]);
enum {arr_size = 999};


int main(void)
{
  int n =0;  
  char arr_str[arr_size] = {};
  in_arr(arr_str);
  print_digit(arr_str);

  return 0;
}

void print_digit(char s[])
{
  int digits[10] = {};
  int i = 0;
  int dig = 0;
  for (i=0; s[i]!= '\0';i++)
  {
  dig = s[i] - '0';
  if (dig>=0 && dig<=9)
  digits[dig]++;
  }
  i = 0;
  for (i;i<10;i++)
  {
    if (digits[i] != 0)
    {
      printf("%d %d\n", i, digits[i]);
    }
  }
}


int in_arr(char *arr)
{ 
  int n;
  n = scanf("%[^\n]", arr);
  return n;
}

