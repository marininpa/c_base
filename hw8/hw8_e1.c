#include <stdio.h>

int in_arr(int *arr);
int print_arr(int *arr);
float aver_arr(int *arr);

int main(void)
{
  int arr[4] = {};
  in_arr(arr);
  printf("%.3f", aver_arr(arr));
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
  for(i=0;i<5;i++)
    printf("%d", arr[i]);
  return 0;
}

float aver_arr(int *arr)
{
  int i;
  float aver = 0;
  for(i=0;i<5;i++)
    {
     aver += arr[i];
    }
  aver = aver/5;
  return aver;
}