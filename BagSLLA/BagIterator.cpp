#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c), sameCount(0)
{
	current = bag.head;
	if (current != -1)
	{
		sameCount = bag.frequency[current];
		sameCount--;
	}
	else
	{
		sameCount = 0;
	}
}

void BagIterator::first() {
	current = bag.head;
	if (current != -1)
	{
		sameCount = bag.frequency[current];
		sameCount--;
	}
	else
	{
		sameCount = 0;
	}
}


void BagIterator::next() {
	if (current == -1)
	{
		throw exception();
	}
	else
	{
		if (sameCount == 0)
		{
			current = bag.next[current];
			if (current != -1)
			{
				sameCount = bag.frequency[current];
				sameCount--;
			}
			else
			{
				sameCount = 0;
			}
		}
		else
		{
			sameCount--;
		}
	}
}


bool BagIterator::valid() const {
	if (current != -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}



TElem BagIterator::getCurrent() const
{
	if (current == -1)
	{
		throw exception();
	}
	else
	{
		return bag.elems[current];
	}
}
