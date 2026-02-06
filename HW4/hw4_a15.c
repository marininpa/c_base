#include <stdio.h>

/*
y=k*x+b
k=(y2-y1)/(x2-x1)
b=y-k*x
*/

int main(void)
{

	int x1 = 0; 
	int x2 = 0; 
	int y1 = 0;
	int y2 = 0;
	float k = 0;
    float b = 0; 
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 != x2)
      {
      k = (float)(y2-y1)/(x2-x1);
      b = (float)y1-k*x1;
      printf("%.2f %.2f", k, b);
	  }
}
