#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
public:
    node *front;
    node *rear;

    Queue()
    {
        front = rear = NULL;
    }

    void Insert(int d)
    {
        if (front == NULL && rear == NULL)
        {
            front = rear = new node(d);
        }
        else
        {
            rear->next = new node(d);
            rear = rear->next;
        }
    }

    void Delete()
    {
        front = front->next;
    }

    void Display()
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << (temp->data) << "\t";
            temp = temp->next;
        }
    }
};

int main()
{
    Queue q1;
    int d;
    q1.Insert(10);
    q1.Insert(20);
    q1.Insert(30);
    q1.Insert(40);
    q1.Insert(50);
    q1.Delete();
    q1.Display();
}