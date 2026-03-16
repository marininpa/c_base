#include <stdio.h>

int in_arr(int *arr);
int f_sort_arr (int *arr);

enum {arr_size = 10};

int main(void)
{
  int sum_max_arr = 0; 
  int arr[arr_size] = {};

  in_arr(arr);
  f_sort_arr(arr);
  sum_max_arr = arr[arr_size - 1] + arr[arr_size - 2];
  printf("%d\n", sum_max_arr);
  return 0;
}

int in_arr(int *arr)
{
  int i;
  for(i=0;i<arr_size;i++)
    scanf("%d", &arr[i]);
  return 0;
}

int f_sort_arr (int *arr)
{
  int i =0;
  int k =0;
  int tmp = 0;
  int no_change = 1;
  for (k=0;k<arr_size-1;k++)
  {
    for (i=0;i<arr_size-1-k;i++)
      {
        if (arr[i] > arr[i+1])
        {
          tmp = arr[i];
          arr[i] = arr[i+1];
          arr[i+1] = tmp;
          no_change = 0;
        }
      }
    if (no_change) break;
    no_change = 1;
   }
}