#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator; 
class Bag {

	class Node
	{
	private:
		TElem value;
		Node* next;
		Node* prev;
		int frequency;

	public:
		Node(TElem& value, Node* next, Node* prev) : value(value)
			, next(next), prev(prev), frequency(1)
		{

		}

		TElem& get_value()
		{
			return value;
		}

		void set_value(const TElem& value)
		{
			this->value = value;
		}

		Node* get_next()
		{
			return next;
		}

		void set_next(Node* next)
		{
			this->next = next;
		}

		Node* get_prev()
		{
			return prev;
		}

		void set_prev(Node* prev)
		{
			this->prev = prev;
		}

		int get_frequency()
		{
			return frequency;
		}

		void set_frequency(int frequency)
		{
			this->frequency = frequency;
		}
	};

private:
	Node* head;
	Node* tail;


	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
};