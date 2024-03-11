#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
void insert(node *root, node *New)
{
    cout << "Where to insert left/right of" << root->data;
    char ch = getchar();
    if (ch == 'r')
    {
        if (root->right == NULL)
            root->right = New;
        else
            insert(root->right, New);
    }
    else
    {
        if (root->left == NULL)
            root->left = New;
        else
            insert(root->left, New);
    }
}
node *get_node()
{
    node *temp;
    temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main()
{
    node *New, *root;
    root = NULL;
    char ans;
    do
    {
        New = get_node();
        cin >> New->data;
        if (root == NULL)
            root = New;
        else
            insert(root, New);
        cout << "do you want to enter more elements ?";
        ans = getchar();
    } while (ans == 'y');
    return 0;
}