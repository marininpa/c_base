#include <stdio.h>
#include <string.h>
enum {size = 1001};

int main(void)
{
char file_string[size] = {};


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
// read input file
if((fgets(file_string, size, f_in))==NULL)
 {
  printf("Входной файл пустой\n");
  // close file
  if (f_in != NULL) fclose(f_in);
  if (f_out != NULL) fclose(f_out);
  return 1;
 }

// меняем символы и выводим в файл
for (int i=0;file_string[i];i++)
{
  switch(file_string[i])
  {
    case 97 :
      fprintf(f_out,"%c", file_string[i]+1);
      break;
    case 98 :
      fprintf(f_out,"%c", file_string[i]-1);
      break;
    case 65 :
      fprintf(f_out,"%c", file_string[i]+1);
      break;
    case 66 :
      fprintf(f_out,"%c", file_string[i]-1);
      break;
    default:
    fprintf(f_out,"%c", file_string[i]);
  }


}

// close file
if (f_in != NULL) fclose(f_in);
if (f_out != NULL) fclose(f_out);
return 0;
}