#include <stdio.h>
#include "temp_api.h"

int main() {
    // Создаем массив из структур
    TemperatureRecord data[] = {
        {2023, 1, 5, 12, 30, -10},
        {2023, 1, 15, 14, 00, -15},
        {2023, 2, 10, 10, 15, -5},
        {2023, 2, 20, 11, 20, 0},
        {2023, 7, 1, 9, 0, 25},
        {2023, 7, 15, 15, 45, 30},
        {2023, 12, 31, 23, 59, -20},
        {2024, 1, 10, 8, 0, -8}
    };

    // Вычисляем количество элементов в массиве
    int data_size = sizeof(data) / sizeof(data[0]);

    int target_year = 2023;
    int target_month = 1;

    printf("=== Статистика за %d год ===\n", target_year);
    printf("Среднегодовая температура: %.1f\n", get_year_avg(data, data_size, target_year));
    printf("Минимальная температура за год: %d\n", get_year_min(data, data_size, target_year));
    printf("Максимальная температура за год: %d\n", get_year_max(data, data_size, target_year));

    printf("\n=== Статистика за %02d.%d ===\n", target_month, target_year);
    printf("Среднемесячная температура: %.1f\n", get_month_avg(data, data_size, target_year, target_month));
    printf("Минимальная температура в месяце: %d\n", get_month_min(data, data_size, target_year, target_month));
    printf("Максимальная температура в месяце: %d\n", get_month_max(data, data_size, target_year, target_month));

    return 0;
}