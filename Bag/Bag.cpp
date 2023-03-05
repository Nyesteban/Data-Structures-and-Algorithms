#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	head = nullptr;
	tail = nullptr;
}
//Theta(1)

void Bag::add(TElem elem) {
	Node* newNode = new Node(elem, nullptr, tail);
	Node* currentNode = head;
	while (currentNode != nullptr && currentNode->get_value() != elem)
	{
		currentNode = currentNode->get_next();
	}
	if (currentNode == nullptr)
	{
		if (this->head == nullptr) {
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			this->tail->set_next(newNode);
			this->tail = newNode;
		}
	}
	else
	{
		currentNode->set_frequency(currentNode->get_frequency() + 1);
	}
}
// Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)

bool Bag::remove(TElem elem) {
	Node* currentNode = head;
	while (currentNode != nullptr && currentNode->get_value() != elem)
	{
		currentNode = currentNode->get_next();
	}
	if (currentNode != nullptr)
	{
		if (currentNode->get_frequency()>1)
		{
			currentNode->set_frequency(currentNode->get_frequency() - 1);
			return true;
		}

		if (currentNode == head)
		{
			if (currentNode == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				head = head->get_next();
				head->set_prev(nullptr);
			}
		}
		else if(currentNode == tail)
		{
			tail = tail->get_prev();
			tail->set_next(nullptr);
		}
		else
		{
			(currentNode->get_next())->set_prev(currentNode->get_prev());
			(currentNode->get_prev())->set_next(currentNode->get_next());
		}
		free(currentNode);
		return true;
	}
	else
	{
		return false;
	}
}
// Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)

bool Bag::search(TElem elem) const {
	Node* currentNode = head;
	while (currentNode != nullptr && currentNode->get_value() != elem)
	{
		currentNode = currentNode->get_next();
	}
	if (currentNode != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)

int Bag::nrOccurrences(TElem elem) const {
	Node* currentNode = head;
	while (currentNode != nullptr && currentNode->get_value() != elem)
	{
		currentNode = currentNode->get_next();
	}
	if (currentNode != nullptr)
	{
		return currentNode->get_frequency();
	}
	else
	{
		return 0;
	}
}
// Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)

int Bag::size() const {
	int bagSize = 0;
	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		bagSize = bagSize + currentNode->get_frequency();
		currentNode = currentNode->get_next();
	}
	return bagSize;
}
//Theta(n)

bool Bag::isEmpty() const {
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Theta(1)

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}
//Theta(1)

Bag::~Bag() {
	auto currentNode = head;
	while (head)
	{
		head = head->get_next();
		delete currentNode;
		currentNode = head;
	}
}
//Theta(n)
