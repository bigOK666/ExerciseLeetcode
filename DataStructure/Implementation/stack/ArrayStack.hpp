#include <iostream>

using namespace std;

class ArrayStack
{
public:
    ArrayStack(int cap) : capacity(cap), stack(new int[cap]), top(-1) {}
    ~ArrayStack()
    {
        delete[] stack;
    }

    bool is_full()
    {
        return top = capacity;
    }

    bool is_empty()
    {
        return top == -1;
    }

    void push(int value)
    {
        if (is_full())
        {
            cerr << "Stack overflow" << endl;
            return;
        }
        top++;
        stack[top] = value;
    }

    int pop()
    {
        if (is_empty())
        {
            cerr << "Stack underflow" << endl;
            return -1;
        }
        return stack[top--];
    }

private:
    int capacity;
    int *stack;
    int top;
};