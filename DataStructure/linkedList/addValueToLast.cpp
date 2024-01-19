// In this node I just developed the simple LinkedList to add value to the last

#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int v) // I have create a constructor to assign the Node values.
    {
        value = v;
        next = NULL;
    }
} *head;

// Node *head;  //We can define the Node type value outside the struct or inside too.

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

void printLinkedList()
{
    Node *curr = head; // Store the head variable to the curr pointer to truck the output

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
    ;
    cout << "Emter the list Node size to add the values" << endl;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cout << "Enter the value of node - " << i << ": ";
        cin >> nodeValue;
        addToLast(nodeValue);
    }
    printLinkedList();
    return 0;
}