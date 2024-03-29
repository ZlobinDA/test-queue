// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/**
* Задание 1
* Требуется написать консольное приложение на C++ для работы с двумя очередями фиксированной длинны,
* состоящими из 32-битных целых беззнаковых чисел. Приложение написать под линукс (приложить мейкфайл).
* В рамках задания не использовать готовые контейнеры, реализующие очередь.
*
* В качестве аргументов программе передаются:
*  - код команды;
*  - аргументы для данной команды, если они предусмотрены.
*
* Программа должна уметь выполнять следующие операции и поддерживать соответствующие команды:
*  - запись/извлечение и печать элемента из очереди;
*  - вывод на экран информации об очереди (размер, содержимое);
*  - вывод на экран содержимого очереди;
*  - вывод элементов очереди, у которых задаваемый пользователем бит равен единице.
*
* Сопроводить код программы комментариями и краткой инструкцией пользователя.
* Остальные детали — на Ваше усмотрение.
*
*/

#include "Queue.h"
#include <cstdint>
#include <ctime>
#include <iostream>
#include <unistd.h>

/**
* 
* В ТЗ нет информации, как будет происходить управление работой программы,
*  поэтому параметры командной строки приведены для демонстрации этой возможности,
*  а управление работой программы частично производится в интерактивном режиме.
* 
* Аргументы командной строки. 
*  -h - справка;
*  -f [размер очереди] - создать очередь 1 с заданным размером;
*  -s [размер очереди] - создать очередь 2 с заданным размером.
*/

int main(int argc, char* argv[]) {
	// Для обработки параметров командной строки используем getopt (вариант 2 - использовать boost).
	/** размер очереди 1 */
	size_t firstQsueueSize = 0;
	/** размер очереди 2 */
	size_t secondQsueueSize = 0;
	int i = 0;
	while ((i = getopt(argc, argv, "hf:s:")) != -1) {
		if (static_cast<char>(i) == '?') {
			continue;
		}
		else if (static_cast<char>(i) == 'h') {
			std::cout << std::endl;
			std::cout << "Консольное приложение для работы с двумя очередями фиксированной длинны," << 
				" состоящими из 32 - битных целых беззнаковых чисел" << std::endl;
			std::cout << "Аргументы командной строки: " << std::endl;
			std::cout << "-h - справка;" << std::endl;
			std::cout << "-f [размер очереди] - создать очередь 1 с заданным размером;" << std::endl;
			std::cout << "-s [размер очереди] - создать очередь 2 с заданным размером." << std::endl;
			return 0;
		}
		else if (static_cast<char>(i) == 'f') {
			std::string _arg = optarg;
			firstQsueueSize = static_cast<size_t>(std::stoi(_arg));
		}
		else if (static_cast<char>(i) == 's') {
			std::string _arg = optarg;
			secondQsueueSize = static_cast<size_t>(std::stoi(_arg));
		}
	}

	std::cout << "Приложение для работы с двумя очередями фиксированной длины" << std::endl;
	// Запускам генерацию рандомных чисел.
	srand(static_cast<unsigned int>(time(nullptr)));

	// Создаем первую очередь фиксированного размера.
	if (firstQsueueSize == 0) {
		std::cout << "Задайте длину первой очереди. Очередь будет заполнена рандомными числами" << std::endl;
		// Проверка ввода отсутствует. Можно сделать с использованием getline.
		std::cin >> firstQsueueSize;
	}
	// Создаем и заполняем рандомными числами от 0 до 9 первую очередь.
	Queue firstQ(firstQsueueSize);
	// При создании проверяем случай переполнение очереди.
	for (size_t i{ 0 }; i < firstQsueueSize + 1; ++i) {
		firstQ.push(rand() % 10);
	}
	// Печать полной информации об очереди.
	firstQ.show_full();
	// Запрос информации о первом элементе о очереди.
	std::cout << "Значение первого элемента в очереди: " << firstQ.front() << std::endl;
	// Проверяем бит числа на равенство единице.
	size_t nBit = 0;
	firstQ.check_bit(nBit);

	// Создаем вторую очередь фиксированного размера.
	if (secondQsueueSize == 0) {
		std::cout << "Задайте длину второй очереди. Очередь будет заполнена рандомными числами" << std::endl;
		// Проверка ввода отсутствует. Можно сделать с использованием getline.
		std::cin >> secondQsueueSize;
	}
	// Создаем и заполняем рандомными числами от 0 до 9 первую очередь.
	Queue secondQ(secondQsueueSize);
	// При создании проверяем случай переполнение очереди.
	for (size_t i{ 0 }; i < secondQsueueSize + 1; ++i) {
		secondQ.push(rand() % 10);
	}
	// Печать полной информации об очереди.
	secondQ.show_full();
	// Запрос информации о первом элементе о очереди.
	std::cout << "Значение первого элемента в очереди: " << secondQ.front() << std::endl;
	// Проверяем бит числа на равенство единице.
	nBit = 2;
	secondQ.check_bit(nBit);
	return 0;
}