## Типы с точно заданной шириной

| Тип | Разрядность (бит) | Знак | Пример диапазона значений |
| :-- | :-- | :-- | :-- |
| `int8_t` | 8 | знаковый | от −128 до 127 |
| `uint8_t` | 8 | без знака | от 0 до 255 |
| `int16_t` | 16 | знаковый | от −32768 до 32767 |
| `uint16_t` | 16 | без знака | от 0 до 65535 |
| `int32_t` | 32 | знаковый | от −2147483648 до 2147483647 |
| `uint32_t` | 32 | без знака | от 0 до 4294967295 |
| `int64_t` | 64 | знаковый | примерно от −9.22e18 до 9.22e18 |
| `uint64_t` | 64 | без знака | от 0 до примерно 1.84e19 |

## printf: спецификаторы для фиксированной длины

| Тип | Десятичный знаковый | Десятичный беззнаковый | Шестнадцатеричный (нижний) | Шестнадцатеричный (верхний) |
| :-- | :-- | :-- | :-- | :-- |
| `int8_t` | `PRId8` | `PRIu8` | `PRIx8` | `PRIX8` |
| `uint8_t` | — | `PRIu8` | `PRIx8` | `PRIX8` |
| `int16_t` | `PRId16` | `PRIu16` | `PRIx16` | `PRIX16` |
| `uint16_t` | — | `PRIu16` | `PRIx16` | `PRIX16` |
| `int32_t` | `PRId32` | `PRIu32` | `PRIx32` | `PRIX32` |
| `uint32_t` | — | `PRIu32` | `PRIx32` | `PRIX32` |
| `int64_t` | `PRId64` | `PRIu64` | `PRIx64` | `PRIX64` |
| `uint64_t` | — | `PRIu64` | `PRIx64` | `PRIX64` |
| `intptr_t` | `PRIdPTR` | `PRIuPTR` | `PRIxPTR` | `PRIXPTR` |
| `uintptr_t` | — | `PRIuPTR` | `PRIxPTR` | `PRIXPTR` |
| `intmax_t` | `PRIdMAX` | `PRIuMAX` | `PRIxMAX` | `PRIXMAX` |
| `uintmax_t` | — | `PRIuMAX` | `PRIxMAX` | `PRIXMAX` |

## scanf: спецификаторы для фиксированной длины

| Тип | Десятичный знаковый | Десятичный беззнаковый | Шестнадцатеричный |
| :-- | :-- | :-- | :-- |
| `int8_t` | `SCNd8` | `SCNu8` | `SCNx8` |
| `uint8_t` | — | `SCNu8` | `SCNx8` |
| `int16_t` | `SCNd16` | `SCNu16` | `SCNx16` |
| `uint16_t` | — | `SCNu16` | `SCNx16` |
| `int32_t` | `SCNd32` | `SCNu32` | `SCNx32` |
| `uint32_t` | — | `SCNu32` | `SCNx32` |
| `int64_t` | `SCNd64` | `SCNu64` | `SCNx64` |
| `uint64_t` | — | `SCNu64` | `SCNx64` |
| `intptr_t` | `SCNdPTR` | `SCNuPTR` | `SCNxPTR` |
| `uintptr_t` | — | `SCNuPTR` | `SCNxPTR` |
| `intmax_t` | `SCNdMAX` | `SCNuMAX` | `SCNxMAX` |
| `uintmax_t` | — | `SCNuMAX` | `SCNxMAX` |

Требуют подключения заголовков:
```c
#include <stdint.h>
#include <inttypes.h>
```