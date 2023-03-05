#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	// empty list
	head = -1;
	//initialize free space
	this->elems = new TElem[cap];
	this->next = new int[cap];
	this->frequency = new int[cap];
	for (int i = 0; i < cap - 1; i++)
	{
		next[i] = i + 1;
		frequency[i] = 0;
	}
	next[cap - 1] = -1;
	firstFree = 0;
}


void Bag::add(TElem elem) {
	int current = head;
	while (current != -1 && elems[current] != elem)
		current = next[current];
	if (current != -1)
	{
		frequency[current]++;
	}
	else
	{
		int newPos = allocateP();
		this->elems[newPos] = elem;
		this->next[newPos] = this->head;
		this->head = newPos;
		frequency[newPos] = 1;
	}
}


bool Bag::remove(TElem elem) {
	int current = this->head;
	int prev = -1;
	while (current != -1 && this->elems[current] != elem)
	{
		prev = current;
		current = this->next[current];
	}
	if (current != -1)
	{
		if (frequency[current] <= 1)
		{
			frequency[current] = 0;
			if (current == this->head)
			{
				this->head = this->next[this->head];
			}
			else
			{
				this->next[prev] = this->next[current];
			}
			this->freeP(current);
			return true;
		}
		else
		{
			frequency[current]--;
			return true;
		}
	}
	else
	{
		return false;
	}
}


bool Bag::search(TElem elem) const {
	int current = head;
	while (current != -1 && elems[current] != elem)
		current = next[current];
	if (current != -1)
		return true;
	else
		return false;
}

int Bag::nrOccurrences(TElem elem) const {
	int current = head;
	while (current != -1 && elems[current] != elem)
		current = next[current];
	if (current != -1)
		return frequency[current];
	else
		return 0;
}


int Bag::size() const {
	int bagSize = 0;
	int current = head;
	while (current != -1)
	{
		bagSize = bagSize + frequency[current];
		current = next[current];
	}
	return bagSize;
}


bool Bag::isEmpty() const {
	if (head == -1)
		return true;
	else
		return false;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[]this->elems;
	delete[]this->next;
	delete[]this->frequency;
}

void Bag::freeP(int pos)
{
	next[pos] = firstFree;
	firstFree = pos;
}

int Bag::allocateP()
{
	if (firstFree == -1)
		this->resize();
	int newFreePos = firstFree;
	firstFree = next[firstFree];
	return newFreePos;
}

void Bag::resize()
{
	int oldCap = this->cap;
	this->cap *= 2;

	TElem* elems = new TElem[this->cap];
	int* next = new int[this->cap];
	int* frequency = new int[this->cap];
	for (int i = 0; i < oldCap; i++)
	{
		elems[i] = this->elems[i];
		next[i] = this->next[i];
		frequency[i] = this->frequency[i];
	}
	for (int i = oldCap; i < this->cap-1; i++)
	{
		next[i] = i + 1;
		frequency[i] = 0;
	}
	next[this->cap - 1] = -1;
	delete[]this->elems;
	delete[]this->next;
	delete[]this->frequency;
	this->elems = elems;
	this->next = next;
	this->frequency = frequency;
	this->firstFree = oldCap;
}
// Theta(nrPairs)

