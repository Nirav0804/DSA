#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
class Impl
{
public:
    Node *head;
    Node *tail;

    Impl()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(int d)
    {
        Node *temp = head;
        Node *n = new Node(d);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            n->prev = temp;
            temp->next = n;
            tail = n;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void rev()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
    void insertAfter(int ee, int ne)
    {
        Node *temp = head;
        Node *n = new Node(ne);
        while (temp->data != ee)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        n->prev = temp;
        temp->next = n;
        n->next->prev = n;
    }
    void insertBefore(int ee, int ne)
    {
        Node *temp = head;
        Node *n = new Node(ne);
        while (temp->next->data != ee)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        n->prev = temp;
        temp->next = n;
        n->next->prev = n;
    }
    void deleteAfter(int ee)
    {
        Node *temp = head;
        while (temp->data != ee)
        {
            temp = temp->next;
        }
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
    }
};

int main()
{
    Impl i1;
    i1.insert(10);
    i1.insert(20);
    i1.insert(30);
    i1.insert(40);
    i1.insert(50);
    i1.display();
    cout << endl;
    // i1.insertAfter(20,60);

    // i1.rev();
    // i1.deleteAfter(30);
    i1.insertBefore(30, 60);
    i1.display();
    return 0;
}