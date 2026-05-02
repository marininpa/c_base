#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"

// Функция вывода справки
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

// --- Работа с динамическим массивом ---

void init_array(TempArray* arr, int initial_capacity) {
    arr->data = (TemperatureRecord*)malloc(initial_capacity * sizeof(TemperatureRecord));
    arr->size = 0;
    arr->capacity = initial_capacity;
}

void free_array(TempArray* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int add_record(TempArray* arr, TemperatureRecord rec) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        TemperatureRecord* temp = (TemperatureRecord*)realloc(arr->data, arr->capacity * sizeof(TemperatureRecord));
        if (!temp) return 0; // Ошибка памяти
        arr->data = temp;
    }
    arr->data[arr->size++] = rec;
    return 1;
}

void delete_record(TempArray* arr, int index) {
    if (index < 0 || index >= arr->size) return;
    
    // Сдвигаем элементы влево, затирая удаляемый
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

// Функция сравнения для qsort (сортировка по дате и времени)
int compare_records(const void* a, const void* b) {
    const TemperatureRecord* ra = (const TemperatureRecord*)a;
    const TemperatureRecord* rb = (const TemperatureRecord*)b;
    
    if (ra->year != rb->year) return ra->year - rb->year;
    if (ra->month != rb->month) return ra->month - rb->month;
    if (ra->day != rb->day) return ra->day - rb->day;
    if (ra->hour != rb->hour) return ra->hour - rb->hour;
    return ra->minute - rb->minute;
}

void sort_array(TempArray* arr) {
    if (arr->size > 1) {
        qsort(arr->data, arr->size, sizeof(TemperatureRecord), compare_records);
    }
}

void print_array(const TempArray* arr) {
    printf("| Год | Мес | День | Час | Мин | Temp |\n");
    printf("|-----|-----|------|-----|-----|------|\n");
    for (int i = 0; i < arr->size; i++) {
        printf("| %04d| %02d | %02d  | %02d  | %02d  | %4d |\n",
               arr->data[i].year, arr->data[i].month, arr->data[i].day,
               arr->data[i].hour, arr->data[i].minute, arr->data[i].temperature);
    }
}

// Парсинг CSV формата: YYYY;MM;DD;HH;MM;Temp
int load_from_csv(TempArray* arr, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла");
        return 0;
    }

    char line[256]; // Буфер
    int line_number = 0;
    int error_count = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        // Пропуск пустых строк
        if (line[0] == '\n' || line[0] == '\r' || line[0] == '\0') {
            continue;
        }

        // Если это первая строка и она не начинается с цифры
        if (line_number == 1) {
            int test_val;
            if (sscanf(line, "%d", &test_val) != 1) {
                continue; // Это заголовок, пропускаем
            }
        }

        int y, m, d, h, mi, t;
        
        // Проверка кол-ва элементов в строке
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &y, &m, &d, &h, &mi, &t) != 6) {
            fprintf(stderr, "[ОШИБКА] Строка %d: неверный формат или неверный разделитель.\n", line_number);
            error_count++;
            continue; // Прерываем обработку только этой строки и идем к следующей
        }

        // Проверка формата данных
        int is_valid = 1;
        
        if (y < 1000 || y > 9999) {
            fprintf(stderr, "[ОШИБКА] Строка %d: год должен быть 4-значным (%d).\n", line_number, y);
            is_valid = 0;
        } else if (m < 1 || m > 12) {
            fprintf(stderr, "[ОШИБКА] Строка %d: месяц вне диапазона 1-12 (%d).\n", line_number, m);
            is_valid = 0;
        } else if (d < 1 || d > 31) {
            fprintf(stderr, "[ОШИБКА] Строка %d: день вне диапазона 1-31 (%d).\n", line_number, d);
            is_valid = 0;
        } else if (h < 0 || h > 23) {
            fprintf(stderr, "[ОШИБКА] Строка %d: часы вне диапазона 0-23 (%d).\n", line_number, h);
            is_valid = 0;
        } else if (mi < 0 || mi > 59) {
            fprintf(stderr, "[ОШИБКА] Строка %d: минуты вне диапазона 0-59 (%d).\n", line_number, mi);
            is_valid = 0;
        } else if (t < -99 || t > 99) {
            fprintf(stderr, "[ОШИБКА] Строка %d: температура вне диапазона -99..99 (%d).\n", line_number, t);
            is_valid = 0;
        }

        if (!is_valid) {
            error_count++;
            continue; // Идем к следующей строке
        }

        // Если все проверки пройдены, добавляем запись в массив
        TemperatureRecord rec = {y, m, d, h, mi, t};
        add_record(arr, rec);
    }

    fclose(file);

    // Итоговое сообщение об импорте (выводим в stderr, чтобы не мешать основному выводу программы)
    if (error_count > 0) {
        fprintf(stderr, "\n[ИМПОРТ] Завершен с ошибками. Успешно загружено: %d, Пропущено из-за ошибок: %d\n", arr->size, error_count);
    } else {
        fprintf(stderr, "\n[ИМПОРТ] Успешно завершен. Загружено записей: %d\n", arr->size);
    }

    return 1;
}

// --- Статистика ---

float get_month_avg(const TempArray* arr, int year, int month) {
    float sum = 0; int count = 0;
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i].year == year && arr->data[i].month == month) {
            sum += arr->data[i].temperature; count++;
        }
    }
    return (count > 0) ? (sum / count) : 0.0f;
}

int get_month_min(const TempArray* arr, int year, int month) {
    int min = 99, found = 0;
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i].year == year && arr->data[i].month == month) {
            if (!found || arr->data[i].temperature < min) { min = arr->data[i].temperature; found = 1; }
        }
    }
    return found ? min : 0;
}

int get_month_max(const TempArray* arr, int year, int month) {
    int max = -99, found = 0;
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i].year == year && arr->data[i].month == month) {
            if (!found || arr->data[i].temperature > max) { max = arr->data[i].temperature; found = 1; }
        }
    }
    return found ? max : 0;
}

float get_year_avg(const TempArray* arr, int year) {
    float sum = 0; int count = 0;
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i].year == year) { sum += arr->data[i].temperature; count++; }
    }
    return (count > 0) ? (sum / count) : 0.0f;
}

int get_year_min(const TempArray* arr, int year) {
    int min = 99, found = 0;
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i].year == year) {
            if (!found || arr->data[i].temperature < min) { min = arr->data[i].temperature; found = 1; }
        }
    }
    return found ? min : 0;
}

int get_year_max(const TempArray* arr, int year) {
    int max = -99, found = 0;
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i].year == year) {
            if (!found || arr->data[i].temperature > max) { max = arr->data[i].temperature; found = 1; }
        }
    }
    return found ? max : 0;
}

void get_unique_years(const TempArray* arr, int* years, int* count) {
    *count = 0;
    for (int i = 0; i < arr->size; i++) {
        int year = arr->data[i].year;
        int is_unique = 1;
        for (int j = 0; j < *count; j++) {
            if (years[j] == year) { is_unique = 0; break; }
        }
        if (is_unique) {
            years[(*count)++] = year;
        }
    }
}