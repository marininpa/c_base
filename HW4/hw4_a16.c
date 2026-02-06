#include <stdio.h>

int main(void)
{

	int a = 0; 
	int b = 0; 
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);
    if (a < b)
      {
        if (b < c)
        {
          printf("YES\n");
        }
        else printf ("NO\n");
      }
      else 
      {
        printf("NO\n");        
      }
      
}
