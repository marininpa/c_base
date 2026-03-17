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
 int odd_count =0;
 int even_count =0;
 int i = 0;
 int k = 0;

 for (i = 0;i < n;i++)
  {
    if ((a[i] == 0))
      {
        tmp_arr[0][odd_count] = a[i];
        odd_count++;
      }
    else if (a[i] % 2 == 0) 
      {
        tmp_arr[0][odd_count] = a[i];
        odd_count++;
      }
    else
      {
        tmp_arr[1][even_count] = a[i];
        even_count++;

      }

  }
  i = 0;
  while (odd_count > 0)
  {
    a[i] = tmp_arr[0][i];
    i++;
    odd_count--;
  }

  while (even_count > 0)
  {
    a[i] = tmp_arr[1][k];
    i++;
    k++;
    even_count--;
  }
  
}