# Компилятор
CC = gcc

# Флаги компиляции (-Wall -Wextra включают вывод предупреждений)
CFLAGS = -Wall -Wextra

# Имя исполняемого файла
TARGET = temp_stat

# Список объектных файлов
OBJS = main.o temp_api.o

# Правило по умолчанию: собрать проект
all: $(TARGET)

# Правило для линковки (создания исполняемого файла из объектных)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Правило для компиляции main.c (зависит от .h файла)
main.o: main.c temp_api.h
	$(CC) $(CFLAGS) -c main.c

# Правило для компиляции temp_api.c (зависит от .h файла)
temp_api.o: temp_api.c temp_api.h
	$(CC) $(CFLAGS) -c temp_api.c

# Правило для очистки директории от скомпилированных файлов
clean:
	rm -f $(OBJS) $(TARGET)
