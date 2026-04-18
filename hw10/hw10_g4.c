#include <stdio.h>
#include <string.h>
enum {size = 101};

int main(void)
{

char check_s1[128] = {0};
char check_s2[128] = {0};
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

 // помечаем все символы из первого слова с подсчётом кол-ва повторений
 int s=0;
 for (int i=0;file_string1[i];i++)
 {
  s = check_s1[file_string1[i]] + 1;
  if (s<2)
  {
    check_s1[file_string1[i]] = s;
  }
  else 
  {
    check_s1[file_string1[i]] = 100;
  }
 }

// помечаем все символы из первого слова с подсчётом кол-ва повторений
s=0;
for (int i=0;file_string2[i];i++)
 {
  s = check_s2[file_string2[i]] + 1;
  if (s<2)
  {
    check_s2[file_string2[i]] = s;
  }
  else 
  {
    check_s2[file_string2[i]] = 100;
  }
 }

 // сравнение первого и второго слова, вывод повторяющихся
 for (int i=0;i<127;i++)
 {
  if (check_s1[i] + check_s2[i] == 2) fprintf(f_out,"%c ", i); 
 }


// close file
if (f_in != NULL) fclose(f_in);
if (f_out != NULL) fclose(f_out);
return 0;
}