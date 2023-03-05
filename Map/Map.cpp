#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	this->elements = new TElem[capacity];
	this->capacity = capacity;
	this->nrPairs = 0;
}
// Theta(1)

Map::Map(const Map& v) {
	this->elements = new TElem[v.capacity];
	this->capacity = v.capacity;
	this->nrPairs = v.nrPairs;

	for (int i = 0; i < v.capacity; i++) {
		this->elements[i] = v.elements[i];
	}
}
// Theta(v.capacity)

Map::~Map() {
	delete[]this->elements;
}
// Theta(1)

Map& Map::operator=(const Map& v) {
	this->nrPairs = v.nrPairs;
	this->capacity = v.capacity;
	delete[] this->elements;
	this->elements = new TElem[v.capacity];

	for (int i = 0; i < v.capacity; i++) {
		this->elements[i] = v.elements[i];
	}
	return *this;
}
// Theta(v.capacity)

TValue Map::add(TKey c, TValue v){

	int index = 0;
	while (index < this->nrPairs) {
		if (this->elements[index].first == c) {
			TValue elem;
			elem = this->elements[index].second;
			this->elements[index].second = v;
			return elem;
		}
		index++;
	}

	if (this->nrPairs == this->capacity)
	{
		this->resize();
	}

	this->elements[this->nrPairs].first = c;
	this->elements[this->nrPairs].second = v;
	this->nrPairs++;

	return NULL_TVALUE;
}
// Best case: Theta(1), Worst case: Theta(nrPairs) => Total Complexity: O(nrPairs)

void Map::resize()
{
	this->capacity *= 2;

	TElem* elements = new TElem[this->capacity];
	for (int i = 0; i < this->nrPairs; i++)
	{
		elements[i] = this->elements[i];
	}

	delete[]this->elements;
	this->elements = elements;
}
// Theta(nrPairs)

TValue Map::search(TKey c) const{

	int index = 0;
	while (index < this->nrPairs) {
		if (this->elements[index].first == c) {
			return this->elements[index].second;
		}
		index++;
	}
	return NULL_TVALUE;
}
// Best case: Theta(1), Worst case: Theta(nrPairs) => Total Complexity: O(nrPairs)

TValue Map::remove(TKey c){

	int index = 0;
	while (index < this->nrPairs) {
		if (this->elements[index].first == c) {
			TValue elem;
			elem = this->elements[index].second;
			this->elements[index] = this->elements[this->nrPairs - 1];
			this->nrPairs--;
			return elem;
		}
		index++;
	}
	return NULL_TVALUE;
}
// Best case: Theta(1), Worst case: Theta(nrPairs) => Total Complexity: O(nrPairs)

int Map::size() const {
	return this->nrPairs;
}
// Theta(1)

bool Map::isEmpty() const{
	if (this->nrPairs == 0) {
		return true;
	}
	else {
		return false;
	}
}
// Theta(1)

MapIterator Map::iterator() const {
	return MapIterator(*this);
}
// Theta(1)



