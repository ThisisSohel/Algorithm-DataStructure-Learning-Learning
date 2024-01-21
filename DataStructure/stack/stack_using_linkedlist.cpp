#include <iostream>

using namespace std;

struct Stack {
    struct Node {
        int value;
        Node *next;

        Node(int v) {
            value = v;
            next = NULL;
        }
    } *head;

    int stackSize;

    Stack() {
        head = NULL;
        stackSize = 0;
    }

    void push(int x) {
        stackSize++;
        if (head == NULL) {
            head = new Node(x);
            return;
        }
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode; // O(1)
    }

    void pop() {
        if (head == NULL) {
            // Handle the case when the stack is empty
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        stackSize--;
        Node *temp = head;
        head = temp->next;
        delete temp; 
    }

    int top() {
        if (head == NULL) {
            // Handle the case when the stack is empty
            cout << "Stack is empty. No top element." << endl;
            return -1; // Assuming -1 represents an invalid value in your context
        }
        return head->value;
    }

    int size() {
        return stackSize;
    }
};

int main() {
    // Example usage of the stack
    Stack myStack;

    int elementNumber, stackElement;
    cout<<"How many numbers do you want to enter into the stack? ";
    cin>>elementNumber;
    for(int i=1; i<=elementNumber; i++){
        cout<<"Enter your element "<<i<<"-> ";
        cin>>stackElement;
        myStack.push(stackElement);
    }
    // myStack.push(5);
    // myStack.push(10);

    cout << "Top element: " << myStack.top() << endl;
    cout << "Stack size: " << myStack.size() << endl;

    myStack.pop();

    cout << "Top element after pop: " << myStack.top() << endl;
    cout << "Stack size after pop: " << myStack.size() << endl;

    return 0;
}
