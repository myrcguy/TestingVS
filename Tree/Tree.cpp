#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

// This program will be used for generating a binary search tree
using namespace std;
class Node
{
public:
    int value;
    Node *next = NULL;
    Node *prev = NULL;
};

void printLinkedList(Node *Head);
Node *addNode(Node *Head);
Node *deleteNode(Node *Head);

int main()
{
    Node *head;
    Node *first;
    Node *second;

    head = new Node();
    first = new Node();
    second = new Node();

    head->value = 10;
    first->value = 2;
    second->value = 4;
    head->next = first;
    first->prev = head;
    first->next = second;
    second->prev = first;

    printLinkedList(head);
    while (true)
    {
        int option;
        cout << "Welcome to the Base" << endl;
        cout << "Select from one of the following options: " << endl;
        cout << "1: Add Node" << endl;
        cout << "2: Dlete Node" << endl;
        cout << "3: Print Data Structure" << endl;
        cin >> option;
        if (option == 1)
        {
            head = addNode(head);
        }
        else if (option == 2)
        {
            head = deleteNode(head);
        }
        else if (option == 3)
        {
            printLinkedList(head);
        }
        else
        {
            cout << "Please Pick an available option" << endl;
        }
    }
}

void printLinkedList(Node *Head)
{
    while (Head != NULL)
    {
        cout << Head->value << "\t";
        Head = Head->next;
    }
    cout << "\n";
}

Node *addNode(Node *Head)
{
    while (Head->next != NULL)
    {
        Head = Head->next;
    }
    Node *newNode = new Node();
    int value;
    cout << "Enter the value for the Node" << endl;
    cin >> value;
    newNode->value = value;
    Head->next = newNode;
    newNode->prev = Head;
    return Head;
}

Node *deleteNode(Node *Head)
{
    cout << "What Node value do you want to delete ?" << endl;
    int nodeValue;
    cin >> nodeValue;
    Node *cur = Head;
    while (cur != NULL)
    {
        cout << "HERE";
        if (cur->value == nodeValue)
        {
            if (cur->prev == NULL)
            {
                Head = cur->next;
                Head->prev = NULL;
                delete cur;
                return Head;
            }

            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            delete cur;
            return Head;
        }
        cur = cur->next;
    }
}