#include <stdio.h>

int in_arr(int *arr);
int f_min_arr(int *arr, int *arr_min_pos);
int f_max_arr(int *arr, int *arr_max_pos);

enum {arr_size = 9};

int main(void)
{
  int arr_min_pos = 0;
  int arr_max_pos = 0;
  int arr_min = 0;
  int arr_max = 0;

  int arr[arr_size] = {};
  in_arr(arr);
  arr_min = f_min_arr(arr, &arr_min_pos);
  arr_max = f_max_arr(arr, &arr_max_pos);
  printf("%d %d %d %d\n", arr_max_pos, arr_max, arr_min_pos, arr_min);
  return 0;
}

int in_arr(int *arr)
{
  int i;
  for(i=0;i<=arr_size;i++)
    scanf("%d", &arr[i]);
  return 0;
}


int f_min_arr(int *arr, int *arr_min_pos)
{
  int i = 0;
  int min = arr[i];
  *arr_min_pos = 1;
  for(i=0;i<=arr_size-1;i++)
  {
    if (min > arr[i+1])
    {
      min = arr[i+1];
      *arr_min_pos = i+2;
    }
  }    
     
  return min;
}

int f_max_arr(int *arr, int *arr_max_pos)
{
  int i = 0;
  int max = arr[i];
  *arr_max_pos = 1;
  for(i=0;i<=arr_size-1;i++)
  {
    if (max < arr[i+1])
    {
      max = arr[i+1];
      *arr_max_pos = i+2;
    }
  }   
      
  return max;
}