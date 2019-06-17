//Written by Jongmin Han
//jongmin.han17@gmail.com
#include <iostream>
using namespace std;

class Stack
{
public:
	Stack(int size);
	~Stack();

	bool Push(int num);
	int Pop();
	int Peek() const;
	bool IsEmpty() const;

private:
	int mTop;
	int mMax;
	int* mArr;
};

Stack::Stack(int size) 
	: mTop(-1)
	, mMax(size)
{
	mArr = new int[size];
}


Stack::~Stack()
{
	delete[] mArr;
}

bool Stack::Push(int num)
{
	if (mTop >= mMax - 1)
	{
		cout << "Stack is full.\n";
		return false;
	}
	else
	{
		mTop++;
		mArr[mTop] = num;
		return true;
	}
}

int Stack::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack is empty.\n";
		return -1;
	}
	else
	{
		int tmp;
		tmp = mArr[mTop];
		mTop--;
		return tmp;
	}
}

int Stack::Peek() const
{
	return mArr[mTop];
}

bool Stack::IsEmpty() const
{
	return mTop < 0;
}

int main()
{
	Stack* st = new Stack(100);

	for (int i = 0; i < 50; i++)
	{
		st->Push(i*i - i + 1);
	}

	while (!st->IsEmpty())
	{
		cout << st->Pop() << endl;
	}

	delete st;
	return 0;
}
