#include <bits/stdc++.h>
using namespace std;
int graph[100][100];
void displaymatrix(int d)
{
    int i, j;
    cout << "Graph in adjeacent matrix is as follows:"
         << "\n";
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {
            cout << graph[i][j] << "\t";
        }
        cout << "\n";
    }
}
void add_edge(int i, int j)
{
    graph[i][j] = 1;
    graph[j][i] = 1;
}
int main()
{
    int d = 8;
    add_edge(1, 0);
    add_edge(1, 5);
    add_edge(2, 0);
    add_edge(2, 5);
    add_edge(3, 0);
    add_edge(5, 0);
    add_edge(4, 0);
    add_edge(5, 7);
    add_edge(7, 6);
    add_edge(6, 3);
    add_edge(6, 4);
    displaymatrix(d);
    return 0;
}
