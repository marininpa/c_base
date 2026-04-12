#include <stdio.h>
#include <string.h>
enum {size = 101};

int main(void)
{

int len = 0;
int count =0;
char file_string1[size] = {};
char file_string2[size] = {};


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
if((fscanf(f_in, "%s %s", file_string1, file_string2))!=2)
 {
  printf("Ошибка чтения входного файла\n");
  // close file
  if (f_in != NULL) fclose(f_in);
  if (f_out != NULL) fclose(f_out);
  return 1;
 }

 // общая длина строки с учётом \n
len = strlen(file_string);
last_s = file_string[len-2];
for (count=0;count<len-2;count++)
{
 if (file_string[count] == last_s) fprintf(f_out,"%d ", count);

}

// close file
if (f_in != NULL) fclose(f_in);
if (f_out != NULL) fclose(f_out);
return 0;
}