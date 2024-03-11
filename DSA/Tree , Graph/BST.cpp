#include <iostream>
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
class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
    }
    Node *getRoot()
    {
        return root;
    }
    void Insert(Node *p, int key)
    {
        Node *tmp = new Node(key);
        Node *q;
        if (root == NULL)
            root = tmp;
        while (p != NULL)
        {
            q = p;
            if (key < p->data)
                p = p->l;
            else if (key > p->data)
                p = p->r;
            else
                return;
        }
        if (key < q->data)
            q->l = tmp;
        else if (key > q->data)
            q->r = tmp;
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
    Node *Search(Node *p, int key)
    {
        while (p != NULL)
        {
            if (p->data == key)
            {
                cout << "Key Present" << endl;
                return p;
            }
            else if (key < p->data)
                p = p->l;
            else
                p = p->r;
        }
        return NULL;
    }
};
int main()
{
    BST A;
    int n, x;
    cout << "Enter no. of Nodes:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Value:";
        cin >> x;
        A.Insert(A.getRoot(), x);
    }
    A.Inorder(A.getRoot());
    cout << "\n";
    Node *tmp = A.Search(A.getRoot(), 7);
    if (tmp == NULL)
        cout << "Key not found" << endl;
    return 0;
}