# Компилятор
CC=g++
# Флаги компилятора
# -g - генерировать отладочную информацию
# -Wall - включить все предупреждения
# -std=c++17 - использовать стандарт с++17
CFLAGS=-g -Wall -std=c++17
# Исходные тексты
SOURCES=Main.cpp Queue.cpp
# Объектные файлы. Получаем из исходников заменой .cpp на .o
OBJECTS=$(SOURCES:.cpp=.o)
# Имя исполняемого модуля
EXE=test-queue

all: $(EXE)
$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS)
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm *.o
clean_all:
	rm $(EXE) *.o