// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Queue.h"
#include <iostream>

Queue::Queue(size_t size) : _size(size), _count(0), _first(nullptr), _last(nullptr) {
#ifdef _DEBUG
	std::cout << "Создана очередь размером " << _size << std::endl;
#endif
}

Queue::~Queue() {
	while (!empty()) {
		pop();
	}
}

void Queue::push(uint32_t value) {
	// Проверяем размер очереди.
	if ((_count + 1) > _size) {
		std::cout << "Внимание! Очередь заполнена полностью. Перед добавлением нового элемента извлеките элемент из очереди"
			<< std::endl;
		return;
	}
#ifdef _DEBUG
	std::cout << "В очередь добавляется узел, содержащий значение " << value << std::endl;
#endif
	// Создаем новый узел.
	Node* newNode = new Node(value);
	// Увеличиваем счетчик узлов.
	++_count;
	// Проверка на пустую очередь.
	if (empty()) {
		_first = _last = newNode;
		return;
	}
	// Добавляем новый узел в конец очереди.
	_last->_next = newNode;
	// Обновляем указатель на последний узел в очереди.
	_last = newNode;
}

void Queue::pop() {
	// Проверка на пустую очередь.
	if (empty()) {
		return;
	}
	// Сохраняем указатель на первый узел очереди.
	Node* deleteNode = _first;
	// Задаем новый первый узел очереди.
	_first = _first->_next;
	// Проверям случай: очередь состоит из 1-ого узла.
	// При удалении единственного уза нужно занулить указатель на конец очереди.
	if (_first == nullptr) {
		_last = nullptr;
	}
	// Удаляем сохраненный (старый) первый узел очереди.
	delete deleteNode;
}

bool Queue::empty() {
	return (_first == nullptr && _last == nullptr);
}

uint32_t Queue::front() {
	if (empty()) {
		// Если очередь пуста, возвращаем 0.
		return 0;
	}
	auto value = _first->_value;
	return value;
}

void Queue::show_full() {
	std::cout << std::endl;
	std::cout << "Информация об очереди" << std::endl;
	std::cout << "Размер очереди: " << _size << std::endl;
	show_data();
}

void Queue::show_data() {
	std::cout << "Содержимое очереди (от первого до последнего элемента): " << std::endl;
	Node* current = _first;
	if (empty()) {
		std::cout << "Очередь пуста" << std::endl;
	}
	while (current != nullptr) {
		std::cout << current->_value << std::endl;
		current = current->_next;
	}
}

void Queue::check_bit(size_t bit) {
	std::cout << "Элементы очереди, у которых " << bit << " бит равен единице: " << std::endl;
	Node* current = _first;
	while (current != nullptr) {
		int nodeValue = current->_value;
		int bitValue = (nodeValue >> bit) & 1;
		if (bitValue == 1) {
			std::cout << nodeValue << std::endl;
		}
		current = current->_next;
	}
}
