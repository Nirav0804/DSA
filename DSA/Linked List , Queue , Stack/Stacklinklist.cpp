#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d, node *temp)
    {
        data = d;
        next = temp;
    }
};
class List
{
public:
    node *top = NULL;
    void pushval(int a)
    {
        node *n = new node(a, top);
        top = n;
    }
    int pop()
    {
        int t = top->data;
        top = top->next;
        return t;
    }
};

int main()
{
    List l1;
    l1.pushval(10);
    l1.pushval(20);
    l1.pushval(30);
    l1.pushval(40);
    l1.pushval(50);
    l1.pushval(60);
    cout << l1.pop() << "\t";
    cout << l1.pop() << "\t";
    cout << l1.pop() << "\t";
    cout << l1.pop() << "\t";
    cout << l1.pop() << "\t";
    cout << l1.pop() << "\t";
    return 0;
}