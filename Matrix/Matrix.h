#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

#include <utility>
#include <stack>

class Matrix {
	/*
	class BSTNode
	{
	private:
		int line;
		int col;
		TElem value;
		BSTNode* left;
		BSTNode* right;

	public:
		BSTNode(int _line, int _col, TElem _value, BSTNode* _left, BSTNode* _right) :
			line(_line), col(_col), value(_value), left(_left), right(_right)
		{

		}
		int getLine()
		{
			return line;
		}
		int getCol()
		{
			return col;
		}
		TElem getValue()
		{
			return value;
		}
		BSTNode* getLeft()
		{
			return left;
		}
		BSTNode* getRight()
		{
			return right;
		}
		void setLine(int _line)
		{
			line=_line;
		}
		void setCol(int _col)
		{
			col=_col;
		}
		void setValue(TElem _value)
		{
			value=_value;
		}
		void setLeft(BSTNode* _left)
		{
			left=_left;
		}
		void setRight(BSTNode* _right)
		{
			right=_right;
		}
	};*/
private:
	int root;
	int* line;
	int* col;
	TElem* value;
	int* left;
	int* right;
	int firstFree;
	int nrOfCols;
	int nrOfLines;
public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	std::pair<int, int> positionOf(TElem elem) const;


	~Matrix();

};
