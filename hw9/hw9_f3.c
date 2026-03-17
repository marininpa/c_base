#include <stdio.h>

int in_arr(char *arr);
int print_arr(char *arr);
enum {arr_size = 999};


int main(void)
{
  int n =0;  
  char arr_str[arr_size] = {};
  in_arr(arr_str);
  print_arr(arr_str);

  return 0;
}

int print_arr(char *arr)
{
  int digits[10] = {};
  int i = 0;
  int dig = 0;
  for (i=0; arr[i]!= '\0';i++)
  {
  dig = arr[i] - '0';
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
  scanf("%s", arr);
  return 0;
}