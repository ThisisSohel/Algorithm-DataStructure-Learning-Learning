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

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteLast()
{
    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = NULL;
}

void deleteAnyPosition(int position)
{
    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *curr = head;
    for (int i = 1; i < position - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
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

    // Output after adding values to the last
    cout << "Linked List after adding values to the last:" << endl;
    printLinkedList();

    deleteFirst();

    // Output after deleting the first node
    cout << "Linked List after deleting the first node:" << endl;
    printLinkedList();

    // Code for deleting the last node...
    deleteLast();

    // Output after deleting the last node
    cout << "Linked List after deleting the last node:" << endl;
    printLinkedList();

    // Code for deleting a node from a specific position...
    int positionToDelete;
    cout << "Enter the position to delete a node: ";
    cin >> positionToDelete;
    deleteAnyPosition(positionToDelete);

    // Output after deleting a node from a specific position
    cout << "Linked List after deleting a node from a specific position:" << endl;
    printLinkedList();

    return 0;
}
