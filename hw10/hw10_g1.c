#include <stdio.h>
enum {size = 1000};

int main(void)
{
char file_string[size] = {};
int count_char = 0, tmp_char =0;
FILE *f_in, *f_out;  
if ((f_in = fopen("input.txt", "r")) == NULL) 
  {
    printf("Ошибка открытия файла input.txt\n");
    return -1;
  }
if ((f_out = fopen("output.txt", "r")) == NULL)
  {
    printf("Ошибка открытия файла output.txt\n");
    fclose(f_in);
    return -1;
  }
//read input file
while((tmp_char=fgetc(f_in))!=EOF)
 {
  file_string[count_char] = tmp_char;
  count_char++;
 }


// close file
if (f_in != NULL) fclose(f_in);
if (f_out != NULL) fclose(f_out);
return 0;
}