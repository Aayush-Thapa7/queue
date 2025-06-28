#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int n)
    {
        data = n;
        next = nullptr;
    }
};

class queue
{
    Node *head;
    Node *tail;
};