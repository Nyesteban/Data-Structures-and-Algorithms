#include "Matrix.h"
#include <exception>
#include <iostream>

using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	   
	// empty list
	root = -1;
	int cap = nrLines * nrCols;
	this->nrOfLines = nrLines;
	this->nrOfCols = nrCols;
	//initialize free space
	this->value = new TElem[cap];
	this->left = new int[cap];
	this->right = new int[cap];
	this->line = new int[cap];
	this->col = new int[cap];
	for (int i = 0; i < cap - 1; i++)
	{
		left[i] = i + 1;
		right[i] = i + 1;
	}
	left[cap - 1] = -1;
	right[cap - 1] = -1;
	firstFree = 0;
}
//Theta(nrLines * nrCols)


int Matrix::nrLines() const {
	return nrOfLines;
}
//Theta(1)

int Matrix::nrColumns() const {
	return nrOfCols;
}
//Theta(1)

TElem Matrix::element(int i, int j) const {
	if (i >= nrLines() || j >= nrColumns() || i<0 || j<0)
		throw std::exception();

	int currentNode = root;
	while (currentNode != -1)
	{
		if (line[currentNode] == i && col[currentNode] == j)
			return value[currentNode];
		else if (i <= line[currentNode])
			currentNode = left[currentNode];
		else
			currentNode = right[currentNode];
	}
	return NULL_TELEM;
}
// Best case: Theta(1), Worst case: Theta(i*j) => Total Complexity: O(i*j)

std::pair<int, int> Matrix::positionOf(TElem elem) const
{
	std::stack<int> s;
	int currentNode = root;
	while (currentNode != -1)
	{
		s.push(currentNode);
		currentNode = left[currentNode];
	}
	while (!s.empty())
	{
		currentNode = s.top();
		s.pop();
		if(value[currentNode]==elem)
			return std::make_pair(line[currentNode], col[currentNode]);
		currentNode = right[currentNode];
		while (currentNode != -1)
		{
			s.push(currentNode);
			currentNode = left[currentNode];
		}
	}
	return std::make_pair(-1,-1);
}
// Best case: Theta(1), Worst case: Theta(cap) => Total Complexity: O(cap)


TElem Matrix::modify(int i, int j, TElem e) {
	if (i >= nrLines() || j >= nrColumns() || i < 0 || j < 0)
		throw std::exception();

	int currentNode = root;
	if (currentNode == -1)
	{
		currentNode = firstFree;
		root = firstFree;
		firstFree = left[firstFree];
		value[currentNode] = e;
		left[currentNode] = -1;
		right[currentNode] = -1;
		line[currentNode] = i;
		col[currentNode] = j;
		return NULL_TELEM;
	}
	while (currentNode != -1)
	{
		if (line[currentNode] == i && col[currentNode] == j)
		{
			TElem returnedValue = value[currentNode];
			value[currentNode] = e;
			line[currentNode] = i;
			col[currentNode] = j;
			return returnedValue;
		}
		else if (i <= line[currentNode])
		{
			int prev = currentNode;
			currentNode = left[currentNode];
			if (currentNode == -1)
			{
				int newPos = firstFree;
				firstFree = left[firstFree];
				left[prev] = newPos;
				value[newPos] = e;
				left[newPos] = -1;
				right[newPos] = -1;
				line[newPos] = i;
				col[newPos] = j;
				return NULL_TELEM;
			}
		}
		else
		{
			int prev = currentNode;
			currentNode = right[currentNode];
			if (currentNode == -1)
			{
				int newPos = firstFree;
				firstFree = right[firstFree];
				right[prev] = newPos;
				value[newPos] = e;
				left[newPos] = -1;
				right[newPos] = -1;
				line[newPos] = i;
				col[newPos] = j;
				return NULL_TELEM;
			}
		}
	}
}
// Best case: Theta(1), Worst case: Theta(i*j) => Total Complexity: O(i*j)

Matrix::~Matrix() {
	delete[]this->value;
	delete[]this->left;
	delete[]this->right;
	delete[]this->line;
	delete[]this->col;
}
//Theta(1)