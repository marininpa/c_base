#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"

#define INITIAL_CAPACITY 10

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

    char line[128];
    // Пропускаем заголовок (если он есть)
    if (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "year", 4) != 0) {
            rewind(file); // Если заголовка нет, возвращаемся в начало
        }
    }

    int y, m, d, h, mi, t;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &y, &m, &d, &h, &mi, &t) == 6) {
            TemperatureRecord rec = {y, m, d, h, mi, t};
            if (m >= 1 && m <= 12 && t >= -99 && t <= 99) {
                add_record(arr, rec);
            }
        }
    }
    fclose(file);
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