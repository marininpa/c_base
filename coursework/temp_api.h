#ifndef TEMP_API_H
#define TEMP_API_H
#include <stdint.h>

// Структура для хранения данных о температуре
typedef struct {
    uint16_t year;   // dddd
    uint8_t month;   // mm
    uint8_t day;     // dd
    uint8_t hour;    // hh
    uint8_t minute;  // mm
    int8_t temperature; // -tt..+tt
} TemperatureRecord;

// Среднемесячная температура
float get_month_avg(const TemperatureRecord* records, int size, int year, int month);

// Минимальная температура в текущем месяце
int get_month_min(const TemperatureRecord* records, int size, int year, int month);

// Максимальная температура в текущем месяце
int get_month_max(const TemperatureRecord* records, int size, int year, int month);

// Среднегодовая температура
float get_year_avg(const TemperatureRecord* records, int size, int year);

// Минимальная температура за год
int get_year_min(const TemperatureRecord* records, int size, int year);

// Максимальная температура за год
int get_year_max(const TemperatureRecord* records, int size, int year);

#endif // TEMP_API_H