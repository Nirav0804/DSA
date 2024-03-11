#include <bits/stdc++.h>
using namespace std;
int graph[100][100];
int dist[3][3];
bool visited[100] = {false};
bool visited1[100] = {false};
void DFS(int v)
{
    if (visited[v])
    {
        return;
    }
    else
    {
        cout << v << "\t";
        visited[v] = true;
        for (int i = 0; i < 8; i++)
        {
            if (graph[v][i])
            {
                DFS(i);
            }
        }
    }
}
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
// finding shortest distance in graph
void shortdistance()
{
    // dist[3][3] = {{0, 4, 11}, {6, 0, 2}, {3, 1000, 0}};
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> dist[i][j];
        }
        cout << "\n";
    }
    for (k = 0; k < 3; k++)
    {
        for (j = 0; j < 3; j++)
        {
            for (i = 0; i < 3; i++)
            {
                if ((dist[j][k] + dist[k][i]) < dist[j][i])
                {
                    dist[j][i] = dist[j][k] + dist[k][i];
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }
}
// BFS implementation
void BFS(int v)
{
    queue<int> q1;
    q1.push(v);
    cout << v << "\t";
    visited1[v] = true;
    while (!q1.empty())
    {
        for (int i = 0; i < 8; i++)
        {
            if (visited1[i] == false && graph[q1.front()][i] == 1)
            {
                q1.push(i);
                cout << i << "\t";
                visited1[i] = true;
            }
        }
        q1.pop();
    }
}
int main()
{
    int d = 8, i;
    add_edge(1, 0);
    add_edge(1, 5);
    add_edge(2, 0);
    add_edge(2, 5);
    add_edge(3, 0);
    add_edge(4, 0);
    add_edge(5, 7);
    add_edge(6, 3);
    add_edge(6, 4);
    add_edge(7, 6);
    displaymatrix(d);
    cout << "\n\n\n";
    cout << "DFS Traversal of the above matrix is as followed:\n";
    DFS(0);
    cout << "\n"
         << "BFS Traversal of the above matrix is as followed:\n";
    BFS(0);
    cout << "\n"
         << "Shortest Distance: ";
    shortdistance();
    return 0;
}