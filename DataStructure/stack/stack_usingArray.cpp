#include <iostream>
#define SIZE 1000000

using namespace std;

// this stack using for number variable
struct intStack
{
    int arr[SIZE];
    int sz;

    intStack()
    {
        sz = 0;
    }

    void push(int x) // O(1)
    {
        arr[sz] = x;
        sz++;
    }
    void pop() // O(1)
    {
        sz--;
    }
    int top() // O(1)
    {
        return arr[sz - 1];
    }
    int size()
    {
        return sz;
    }
};

// This stack is using for Character
struct charStack
{
    int arr[SIZE];
    int sz;

    charStack()
    {
        sz = 0;
    }

    void push(char x) // O(1)
    {
        arr[sz] = x;
        sz++;
    }
    void pop() // O(1)
    {
        sz--;
    }
    char top() // O(1)
    {
        return arr[sz - 1];
    }
    int size()
    {
        return sz;
    }
};

int main()
{
    intStack myStack;

    // Pushing elements onto the stack
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    // Displaying the current state of the stack
    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;

    // Popping an element from the stack
    myStack.pop();

    // Displaying the updated state of the stack
    cout << "Stack size after pop: " << myStack.size() << endl;
    cout << "Top element after pop: " << myStack.top() << endl;

    return 0;
}
