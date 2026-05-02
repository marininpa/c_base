#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "temp_api.h"


int main(int argc, char* argv[]) {
    char* filename = NULL;
    int target_month = 0; // 0 означает, что месяц не задан

    // Парсинг аргументов командной строки
    int opt;
    while ((opt = getopt(argc, argv, "hf:m:")) != -1) {
        switch (opt) {
            case 'h':
                print_help(argv[0]);
                return 0;
            case 'f':
                filename = optarg;
                break;
            case 'm':
                target_month = atoi(optarg);
                if (target_month < 1 || target_month > 12) {
                    fprintf(stderr, "Ошибка: Номер месяца должен быть от 1 до 12.\n");
                    return 1;
                }
                break;
            default:
                print_help(argv[0]);
                return 1;
        }
    }

    if (!filename) {
        fprintf(stderr, "Ошибка: Не указан входной файл. Используйте ключ -f.\n\n");
        print_help(argv[0]);
        return 1;
    }

    // Инициализация и загрузка данных
    TempArray arr;
    init_array(&arr, INITIAL_CAPACITY);
    
    if (!load_from_csv(&arr, filename)) {
        free_array(&arr);
        return 1;
    }

    sort_array(&arr);
    printf("Загружено записей: %d\n\n", arr.size);

    // Получаем список уникальных лет
    int years[100];
    int year_count = 0;
    get_unique_years(&arr, years, &year_count);

    // Вывод статистики
    printf("\n| Year | Month |   Avg |   Max |   Min |\n");
    printf("|------|-------|-------|-------|-------|\n");
    for (int i = 0; i < year_count; i++) {
        int y = years[i];
        
        if (target_month != 0) {
            // Ключ -m УКАЗАН: выводим статистику только для одного месяца
            printf("| %4d | %5d | %5.1f | %5d | %5d |\n",
                   y, target_month,
                   get_month_avg(&arr, y, target_month),
                   get_month_max(&arr, y, target_month),
                   get_month_min(&arr, y, target_month));
            } else {
            // Ключ -m НЕ УКАЗАН: выводим статистику за ВСЕ 12 месяцев
              for (int m = 1; m <= 12; m++) {
                // Если в файле нет данных за какой-то месяц, функции вернут 0
                printf("| %4d | %5d | %5.1f | %5d | %5d |\n",
                       y, m,
                       get_month_avg(&arr, y, m),
                       get_month_max(&arr, y, m),
                       get_month_min(&arr, y, m));

              }
            printf("|------|-------|-------|-------|-------|\n");
            printf("| %4d | TOTAL | %5.1f | %5d | %5d |\n",
                   y,
                   get_year_avg(&arr, y),
                   get_year_max(&arr, y),
                   get_year_min(&arr, y));
            printf("|------|-------|-------|-------|-------|\n");
            // Выводим статистику за весь год
            }
    }

    // Очистка памяти
    free_array(&arr);

    return 0;
}