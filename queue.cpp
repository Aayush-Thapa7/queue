#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
    Node(int n)
    {
        value = n;
        next = nullptr;
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }
    void enqueue(int n)
    {
        Node *newNode = new Node(n);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    };
    void dequeue()
    {
        if (head == nullptr)
        {
            cout << "Nothing to remove" << endl;
            return;
        }

        cout << "The value to remove is :" << head->value << endl;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void traverse()
    {
        if (head == nullptr)
        {
            cout << "[]" << endl;
            return;
        }
        Node *temp = head;
        cout << "[";
        while (temp->next != nullptr)
        {
            cout << temp->value << ", ";
            temp = temp->next;
        }
        cout << temp->value << "]" << endl;
    }
    void isempty()
    {
        if (head == nullptr)
        {
            cout << "Is Empty" << endl;
        }
        else
        {
            cout << "Is not Empty" << endl;
        }
    };
};
int main()
{
    Queue myq;
    string option;
    int sw;
    int n;
    cout << "Hello ,Welcome to the Queue" << endl;
    cout << "Press 1 to add element" << endl;
    cout << "Press 2 to remove element" << endl;
    cout << "Press 3 to traverse" << endl;

    while (option != "Q" || option == "q")
    {
        cout << "Enter your option :";
        cin >> sw;
        switch (sw)
        {
        case 1:
            cout << "Enter the number :";
            cin >> n;
            myq.enqueue(n);
            break;
        case 2:
            myq.dequeue();
            break;

        case 3:
            myq.traverse();
            break;
        }
        cout << "Do you want to quit ? Q/N :";
        cin >> option;
    }
}