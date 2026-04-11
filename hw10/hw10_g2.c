#include <stdio.h>
enum {size = 1000};
enum {count = 3};

int main(void)
{
char file_string[size] = {};
int check_flag = 0;
int read_data = 0;
int num = 2;
char out_char = 'A';
int count = 1;
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
if((check_flag=fscanf(f_in, "%d", &read_data))==EOF)
 {
  printf("Входной файл пустой\n");
  // close file
  if (f_in != NULL) fclose(f_in);
  if (f_out != NULL) fclose(f_out);
  return 1;
 }

 // write to output file
for (count =1;count<=read_data;count++)
{
 if (count %2 == 0) 
 {
  if (num >8) num =2;
  fprintf(f_out, "%d", num);
  num +=2;
 }
else 
{
  fprintf(f_out, "%c", out_char);
  out_char++;
}
}
// close file
if (f_in != NULL) fclose(f_in);
if (f_out != NULL) fclose(f_out);
return 0;
}