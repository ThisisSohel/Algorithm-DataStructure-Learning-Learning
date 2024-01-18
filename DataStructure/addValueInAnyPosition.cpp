#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int v)
    {
        value = v;
        next = NULL;
    }
} *head;

void addToLast(int v)
{
    if (head == NULL)
    {
        head = new Node(v);
        return;
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new Node(v);
}

void addToFirst(int v)
{
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void addToPosition(int v, int position)
{
    if (position < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *newNode = new Node(v);

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *curr = head;
    for (int i = 1; i < position - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void printLinkedList()
{
    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }
}

int main()
{
    head = NULL;

    int num, nodeValue;
    cout << "Enter the number of nodes to add values: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cout << "Enter the value of node - " << i << ": ";
        cin >> nodeValue;
        addToLast(nodeValue);
    }

    cout << "Linked List after adding values to the last:" << endl;
    printLinkedList();

    int valueToAddFirst;
    cout << "Enter the value to add to the first node: ";
    cin >> valueToAddFirst;
    addToFirst(valueToAddFirst);

    cout << "Linked List after adding value to the first node:" << endl;
    printLinkedList();

    int valueToAdd, position;
    cout << "Enter the value to add: ";
    cin >> valueToAdd;
    cout << "Enter the position to add the value: ";
    cin >> position;
    addToPosition(valueToAdd, position);

    cout << "Linked List after adding value to a specific position:" << endl;
    printLinkedList();

    return 0;
}
