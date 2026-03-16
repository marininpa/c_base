#include <stdio.h>

int in_arr(int *arr);
int f_sum_arr(int *arr);

enum {arr_size = 10};

int main(void)
{
  int sum_arr = 0; 
  int arr[arr_size] = {};

  in_arr(arr);
  printf("%d\n", f_sum_arr(arr));
  return 0;
}

int in_arr(int *arr)
{
  int i;
  for(i=0;i<arr_size;i++)
    scanf("%d", &arr[i]);
  return 0;
}

int f_sum_arr(int *arr)
{
int i =0;
int l_arr_summ = 0;
for (i=0; i<arr_size; i++)
  l_arr_summ += (arr[i] >0 ? arr[i] : 0);

return l_arr_summ;
}