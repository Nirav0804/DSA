#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *l;
    Node *r;
    Node() {}
    Node(int x)
    {
        data = x;
        l = r = NULL;
    }
};
class Tree
{
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }
    Node *getRoot()
    {
        return root;
    }
    void Create(Node *p, Node *tmp)
    {
        char x;
        if (root == NULL)
        {
            root = tmp;
        }
        else
        {
            cout << "l or r:";
            cin >> x;
            if (x == 'l')
            {
                if (p->l == NULL)
                    p->l = tmp;
                else
                    Create(p->l, tmp);
            }
            else if (x == 'r')
            {
                if (p->r == NULL)
                    p->r = tmp;
                else
                    Create(p->r, tmp);
            }
        }
    }
    void Preorder(Node *p)
    {
        if (p == NULL)
            return;
        else
        {
            cout << p->data << " ";
            Preorder(p->l);
            Preorder(p->r);
        }
    }
    void Inorder(Node *p)
    {
        if (p == NULL)
            return;
        else
        {
            Inorder(p->l);
            cout << p->data << " ";
            Inorder(p->r);
        }
    }
    void Postorder(Node *p)
    {
        if (p == NULL)
            return;
        Postorder(p->l);
        Postorder(p->r);
        cout << p->data << " ";
    }
    void Levelorder(Node *p)
    {
        if (p == NULL)
            return;
        queue<Node *> Q;
        Q.push(p);
        while (!Q.empty())
        {
            cout << Q.front()->data << " ";
            if (Q.front()->l != NULL)
                Q.push(Q.front()->l);
            if (Q.front()->r != NULL)
                Q.push(Q.front()->r);
            Q.pop();
        }
    }
};
int main()
{
    Tree A;
    int n, x;
    cout << "Enter no. of Nodes:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Value:";
        cin >> x;
        Node *tmp = new Node(x);
        A.Create(A.getRoot(), tmp);
    }
    A.Preorder(A.getRoot());
    cout << '\n';
    A.Inorder(A.getRoot());
    cout << '\n';
    A.Postorder(A.getRoot());
    cout << '\n';
    A.Levelorder(A.getRoot());
    cout << '\n';
    return 0;
}