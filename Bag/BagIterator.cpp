#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c), sameCount(0)
{
	currentElem = bag.head;
	if (currentElem != nullptr)
	{
		sameCount = currentElem->get_frequency();
		sameCount--;
	}
	else
	{
		sameCount = 0;
	}
}
//Theta(1)

void BagIterator::first() {
	currentElem = bag.head;
	if (currentElem != nullptr)
	{
		sameCount = currentElem->get_frequency();
		sameCount--;
	}
	else
	{
		sameCount = 0;
	}
}
//Theta(1)

void BagIterator::next() {
	if (currentElem == nullptr)
	{
		throw exception();
	}
	else
	{
		if (sameCount == 0)
		{
			currentElem = currentElem->get_next();
			if (currentElem != nullptr)
			{
				sameCount = currentElem->get_frequency();
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
//Theta(1)

bool BagIterator::valid() const {
	if (currentElem != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Theta(1)


TElem BagIterator::getCurrent() const
{
	if (currentElem == nullptr)
	{
		throw exception();
	}
	else
	{
		return currentElem->get_value();
	}
}
//Theta(1)