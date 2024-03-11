#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *link;
    Node(int a)
    {
        data = a;
        link = NULL;
    }
};
class List
{
    Node *head = NULL;

public:
    void insert(int a)
    {
        if (head == NULL)
        {
            head = new Node(a);
        }
        else
        {
            Node *temp = head;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new Node(a);
        }
    }
    void insertathead(int a)
    {
        Node *nn = new Node(a);
        Node *temp = head;
        if (head == NULL)
        {
            head = nn;
        }
        else
        {
            nn->link = head;
            head = nn;
        }
    }
    List rev()
    {
        List revv;
        Node *temp = head;
        while (temp != NULL)
        {
            revv.insertathead(temp->data);
            temp = temp->link;
        }
        return revv;
    }
    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->link;
        }
    }
    Node *gethead()
    {
        return head;
    }
};
main()
{
    List l1, l2;
    Node *revlisthead;
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.insert(50);
    l1.insert(60);
    l1.Display();
    l2 = l1.rev();
    l2.Display();
}