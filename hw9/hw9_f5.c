#include <stdio.h>

int in_arr(int *arr);
int find_max_array(int size, int a[]);
enum {arr_size = 999};
int arr_count =0;

int main(void)
{
  int n =0;  
  int arr[arr_size] = {};
  arr_count = in_arr(arr);
  find_max_array(arr_count, arr);

  return 0;
}

int find_max_array(int size, int a[])
{
  int i = 0;
  int max = a[i];
  for(i=0;i<size-1;i++)
  {
    if (max < a[i+1])
    {
      max = a[i+1];
    }
  }   
  printf("%d\n",max);
}
 
int in_arr(int *arr)
{ 
  int num =0;
  int l_count = 0;
  char ch = ' ';
  while (scanf("%d%c", &num, &ch)==2 && l_count<arr_size)
  { 
    arr[l_count++] = num;
    if (ch == '\n' || ch == '\x03') break;
  }
  return l_count;
}

