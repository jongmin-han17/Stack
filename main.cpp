#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int max;
    int* arr;
public:
    Stack(int size)
    {
        top = -1;
        arr = new int[size];
        max = size;
    }

    ~Stack()
    {
        delete []arr;
    }

    bool Push(int num);
    int Pop();
    int Peek() const;
    bool IsEmpty() const;
};

bool Stack::Push(int num)
{
    if (top >= max-1)
    {
        cout << "Stack overflow.\n";
        return false;
    }
    else
    {
        top++;
        arr[top] = num;
        return true;
    }

}

int Stack::Pop()
{
    if (top <= -1)
    {
        cout << "Stack underflow.\n";
        return -1;
    }
    else
    {
        int n = arr[top];
        top--;
        return n;
    }
}

int Stack::Peek() const
{
    return arr[top];
}

bool Stack::IsEmpty() const
{
    return top < 0;
}

int main()
{
    Stack* st = new Stack(100);

    for (int i=0; i< 50; i++)
        st->Push(i*i-i+1);

    while (!st->IsEmpty())
        cout << st->Pop() << endl;

    delete st;
    return 0;
}
