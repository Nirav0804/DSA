#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d, node *t)
    {
        data = d;
        next = t;
    }
};

class impl
{
public:
    node *head;

    impl()
    {
        head = NULL;
    }

    void insertatend(int d)
    {
        if (head == NULL)
        {
            head = new node(d, head);
            head->next = head;
        }

        else
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = new node(d, head);
            // first = temp->next;
        }
    }
    void insertathead(int d)
    {
        if (head == NULL)
        {
            head = new node(d, head);
            head->next = head;
        }

        else
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = new node(d, head);
            head = temp->next;
        }
    }
    void display()
    {
        node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << "\t";
    }
};

int main()
{
    impl l1;
    l1.insertatend(10);
    l1.insertatend(20);
    l1.insertatend(30);
    l1.insertathead(40);
    l1.display();
}