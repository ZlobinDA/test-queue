#pragma once
#include <cstdint>

/** Класс, описывающий узел однонаправленной очереди, состоящей из 32-битных целых беззнаковых чисел. */
class Node {
public:
	uint32_t _value;	/** число хранящееся в узле */
	Node* _next;		/** указатель на следующий узел очереди. */

	Node(uint32_t value) : _value(value), _next(nullptr) {};
};
