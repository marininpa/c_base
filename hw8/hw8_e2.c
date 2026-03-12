#include <stdio.h>

int in_arr(int *arr);
int print_arr(int *arr);
float aver_arr(int *arr);
int min_arr(int *arr);

enum {arr_size = 4};

int main(void)
{
  int arr[arr_size] = {};
  in_arr(arr);
  printf("%d\n", min_arr(arr));
  return 0;
}

int in_arr(int *arr)
{
  int i;
  for(i=0;i<5;i++)
    scanf("%d", &arr[i]);
  return 0;
}

int print_arr(int *arr)
{
  int i;
  for(i=0;i<=arr_size;i++)
    printf("%d\5 n", arr[i]);
  return 0;
}

float aver_arr(int *arr)
{
  int i;
  float aver = 0;
  for(i=0;i<=arr_size;i++)
    {
     aver += arr[i];
    }
  aver = aver/(arr_size+1);
  return aver;
}

int min_arr(int *arr)
{
  int i;
  int min = arr[0];
  for(i=0;i<=arr_size-1;i++)
    if (min > arr[i+1])
      min = arr[i+1];
    //min = (min > arr[i+1]) ? arr[i+1] : arr[i];
  return min;
}