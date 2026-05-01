#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "temp_api.h"

void print_help(const char* program_name) {
    printf("Использование: %s [-h] [-f файл.csv] [-m месяц]\n", program_name);
    printf("Функционал:\n");
    printf("  Чтение данных о температуре из CSV файла.\n");
    printf("  Вывод статистики (средняя, мин, макс) за каждый месяц или за конкретный месяц.\n");
    printf("Ключи:\n");
    printf("  -h  Показать эту справку и выйти.\n");
    printf("  -f  Указать входной CSV файл для обработки.\n");
    printf("  -m  Указать номер месяца (1-12) для вывода статистики ТОЛЬКО за этот месяц.\n");
    printf("      Если ключ -m не задан, выводится статистика за все месяцы по очереди.\n");
}

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
    for (int i = 0; i < year_count; i++) {
        int y = years[i];
        
        if (target_month != 0) {
            // Ключ -m УКАЗАН: выводим статистику только для одного месяца
            printf("=== Статистика за %02d.%d ===\n", target_month, y);
            printf("Средняя температура: %.1f\n", get_month_avg(&arr, y, target_month));
            printf("Минимальная: %d\n", get_month_min(&arr, y, target_month));
            printf("Максимальная: %d\n\n", get_month_max(&arr, y, target_month));
        } else {
            // Ключ -m НЕ УКАЗАН: выводим статистику за ВСЕ 12 месяцев
            printf("========== Статистика за %d год ==========\n", y);
            for (int m = 1; m <= 12; m++) {
                // Если в файле нет данных за какой-то месяц, функции вернут 0
                printf("--- Месяц: %02d ---\n", m);
                printf("  Средняя: %.1f\n", get_month_avg(&arr, y, m));
                printf("  Мин: %d\n", get_month_min(&arr, y, m));
                printf("  Макс: %d\n\n", get_month_max(&arr, y, m));
            }
        }
        // Выводим статистику за весь год
        printf("=== Статистика за %d год ===\n", y);
        printf("Среднегодовая температура: %.1f\n", get_year_avg(&arr, y));
        printf("Минимальная за год: %d\n", get_year_min(&arr, y));
        printf("Максимальная за год: %d\n\n", get_year_max(&arr, y));
    }

    // Очистка памяти
    free_array(&arr);

    return 0;
}