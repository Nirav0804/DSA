#include <iostream>
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
class imp
{
public:
    node *head;
    imp()
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
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << "\t";
    }

    void insertatfirst(int elm)
    {
        node *nn = new node(elm);
        nn->next = head;
        head = nn;
    }

    void insertafter(int elm, int dt)
    {
        node *temp = head;
        while (temp->data != dt)
        {
            temp = temp->next;
        }
        node *nn = new node(elm);
        nn->next = temp->next;
        temp->next = nn;
    }

    void insertbefore(int elm, int dt)
    {
        node *temp = head;
        while (temp->next->data != dt)
        {
            temp = temp->next;
        }
        node *nn = new node(elm);
        nn->next = temp->next;
        temp->next = nn;
    }

    void deletebefore(int elm)
    {
        node *temp = head;
        while (temp->next->next->data != elm)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }

    void deleteafter(int elm)
    {
        node *temp = head;
        while (temp->next->data != elm)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    void insertafterpos(int pos, int dt)
    {
        node *temp = head;
        int i = 1;
        while (i != pos)
        {
            temp = temp->next;
            i++;
        }
        node *nn = new node(dt);
        nn->next = temp->next;
        temp->next = nn;
    }
    void insertbeforepos(int pos, int dt)
    {
        node *temp = head;
        int i = 1;
        while (i + 1 != pos)
        {
            temp = temp->next;
            i++;
        }
        node *nn = new node(dt);
        nn->next = temp->next;
        temp->next = nn;
    }

    node *gethead()
    {
        return head;
    }
    void Reverse()
    {
        node *curr = head;
        node *perv = NULL;
        node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = perv;
            perv = curr;
            curr = next;
        }
        head = perv;
    }
};
node *Rdisplay(node *first)
{
    node *temp = first;
    if (temp == NULL)
        return temp;
    else
    {
        Rdisplay(temp->next);
        cout << temp->data << "\t";
    }
}

int main()
{
    imp i1;
    node *c;
    i1.insertatend(10);
    i1.insertatend(20);
    i1.insertatend(30);
    i1.insertatend(40);
    // i1.insertbeforepos(2, 60);
    // i1.insertafterpos(4, 50);
    // i1.insertatfirst(10);
    // i1.insertatfirst(20);
    // i1.insertatfirst(30);
    // i1.insertatfirst(40);
    // i1.insertatfirst(50);
    // i1.insertatfirst(5);
    // i1.insertafter(13, 10);
    // i1.insertafter(23, 20);
    // i1.insertbefore(21, 23);
    // i1.deletebefore(40);
    // i1.deleteafter(30);
    i1.Reverse();
    i1.display();
    // c = Rdisplay(i1.gethead());
    return 0;
}