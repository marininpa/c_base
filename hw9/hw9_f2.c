#include <stdio.h>

int in_arr(int *arr);
void sort_even_odd(int n, int a[]);
void print_arr (int size, int a[]);

enum {arr_size = 10};

int main(void)
{
  int arr[arr_size] = {};

  in_arr(arr);
  sort_even_odd(arr_size, arr);
  print_arr(arr_size, arr);
  return 0;
}

int in_arr(int *arr)
{
  int i;
  for(i=0;i<arr_size;i++)
    scanf("%d", &arr[i]);
  return 0;
}

void print_arr (int size, int a[])
{
 int i =0;
 for (i=0;i<size;i++)
 printf("%d ", a[i]);
}

void sort_even_odd(int n, int a[])
{
 int tmp_arr[2][n];
 int left =0;
 int right = n-1;
 int i = 0;
 while (i < n-1) 
 {
   while ((left < right) && (a[left] % 2 ==0)) 
   {
     left++;
   }
   while ((left < right) && (a[right] % 2 !=0)) 
   {
     right--;
   }
   tmp_arr[1][i] = a[left];
   tmp_arr[2][i] = a[right];

 }
}