#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>

#define INITIAL_CAPACITY 10

// Исходная структура данных
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} TemperatureRecord;

// для динамического массива
typedef struct {
    TemperatureRecord* data; // Указатель на массив
    int size;                // Текущее количество элементов
    int capacity;            // Зарезервированная память (емкость)
} TempArray;

// --- Функции работы с массивом ---
void init_array(TempArray* arr, int initial_capacity);
void free_array(TempArray* arr);
int add_record(TempArray* arr, TemperatureRecord rec);
void delete_record(TempArray* arr, int index);
void sort_array(TempArray* arr);
void print_array(const TempArray* arr);
int load_from_csv(TempArray* arr, const char* filename);

// --- Функции статистики ---
float get_month_avg(const TempArray* arr, int year, int month);
int get_month_min(const TempArray* arr, int year, int month);
int get_month_max(const TempArray* arr, int year, int month);

float get_year_avg(const TempArray* arr, int year);
int get_year_min(const TempArray* arr, int year);
int get_year_max(const TempArray* arr, int year);

// Вспомогательная функция для получения уникальных лет в массиве
void get_unique_years(const TempArray* arr, int* years, int* count);

#endif // TEMP_API_H