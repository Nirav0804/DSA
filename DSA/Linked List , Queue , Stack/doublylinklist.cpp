#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int d)
    {
        data = d;
        next = prev = NULL;
    }
};

class List
{
public:
    node *head;
    List()
    {
        head = NULL;
    }

    void insertatend(int d)
    {
        node *n = new node(d);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *temp = head;
            // node *nn = new node(d);
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            n->prev = temp;
            temp->next = n;
        }
    }

    void insertafter(int dt, int ele)
    {
        node *temp = head;
        node *n = new node(ele);
        while (temp->data != dt)
        {
            temp = temp->next;
        }
        n->prev = temp;
        temp->next->prev = n;
        n->next = temp->next;
        temp->next = n;
    }

    void insertbefore(int dt, int ele)
    {
        node *temp = head;
        node *n = new node(ele);
        while (temp->data != dt)
        {
            temp = temp->next;
        }
        n->prev = temp->prev;
        n->next = temp;
        temp->prev->next = n;
        temp->prev = n;
    }
    void insertatpos(int pos, int ele)
    {
        node *temp = head;
        node *n = new node(ele);
        int i = 1;
        while (i != pos)
        {
            i++;
            temp = temp->next;
        }
        n->prev = temp->prev;
        n->next = temp;
        temp->prev->next = n;
        temp->prev = n;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }
};

int main()
{
    List l1;
    l1.insertatend(10);
    l1.insertatend(20);
    l1.insertatend(30);
    l1.insertatend(40);
    l1.insertatend(50);
    l1.insertatend(60);
    l1.insertafter(50, 55);
    l1.insertbefore(30, 25);
    l1.insertatpos(2, 11);
    l1.display();
    return 0;
}