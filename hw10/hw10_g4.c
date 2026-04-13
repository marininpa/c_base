#include <stdio.h>
#include <string.h>
enum {size = 101};

int main(void)
{

char check_s[128] = {0};
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

 // помечаем все символы в первом слове
 for (int i=0;file_string1[i];i++)
 {
  check_s[file_string1[i]] = 1;
 }

// сравниваем с символами второго слова
int s=0;
for (int i=0;file_string2[i];i++)
{
  s = check_s[file_string2[i]] + 1;
  check_s[file_string2[i]] = s;
}

// вывод повторяющихся символов
for (int i = 0;i<127;i++)
{
  if (check_s[i] == 2) 
  printf("%c ", i);
}
printf("\n");

// close file
if (f_in != NULL) fclose(f_in);
if (f_out != NULL) fclose(f_out);
return 0;
}