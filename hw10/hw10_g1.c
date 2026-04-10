#include <stdio.h>
enum {size = 1000};
enum {count = 3};

int main(void)
{
char file_string[size] = {};
int count_char = 0, tmp_char =0, count_write = count, count_out =0;
FILE *f_in, *f_out;  
if ((f_in = fopen("input.txt", "r")) == NULL) 
  {
    printf("Ошибка открытия файла input.txt\n");
    return -1;
  }
if ((f_out = fopen("output.txt", "w+")) == NULL)
  {
    printf("Ошибка открытия файла output.txt\n");
    fclose(f_in);
    return -1;
  }
// read input file
while((tmp_char=fgetc(f_in))!=EOF)
 {
  if (tmp_char=='\n') continue;
  file_string[count_char] = tmp_char;
  count_char++;
 }

 // write ti output file
for (count_write; count_write>0;count_write--)
 {
  count_out = 0;
  while (count_out!=count_char)
  {
    fputc(file_string[count_out], f_out);
    count_out++;
  }
  if (count_write==1) continue;
  fprintf(f_out, ", ");
 }
 fprintf(f_out," %d", count_char);

// close file
if (f_in != NULL) fclose(f_in);
if (f_out != NULL) fclose(f_out);
return 0;
}