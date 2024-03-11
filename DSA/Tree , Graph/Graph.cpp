#include<bits/stdc++.h>
#define N 5
using namespace std;

class Graph
{
    public:
    void Create(int arr[][N+1])
    {
        cout<<"Enter Matrix:\n";
        for(int i=0;i<=N;i++)
            {
                for(int j=0;j<=N;j++)
                    {
                        if(i==0 || j==0)
                            arr[i][j]=0;
                        else
                            cin>>arr[i][j];
                    }
            }
    }
    void BFS(int arr[][N+1],int visited[],int num)
    {
        queue<int> Q;
        Q.push(num);
        cout<<Q.front()<<" ";
        visited[num]=1;
        while(!Q.empty())
            {
                int i=Q.front();
                Q.pop();
                for(int j=1;j<=N;j++)
                    {
                        if(arr[i][j] && visited[j]==0)
                            {
                                
                                cout<<j<<" ";
                                visited[j]=1;
                                Q.push(j);
                            }
                    }  
            }
    }
    void DFS(int arr[][N+1],int visited[],int num)
    {
        
        if(visited[num]==0)
            {
                cout<<num<<" ";
                visited[num]=1;
                for(int j=1;j<=N;j++)
                    {
                        if(arr[num][j]==1 && visited[j]==0)
                            DFS(arr,visited,j);
                    }
            }
    }
};

int main()
{
    Graph A;
    int arr[N+1][N+1];
    int vis1[N+1]={0};
    A.Create(arr);
    
    cout<<"DFS:\n";
    A.DFS(arr,vis1,1);

    int vis2[N+1]={0};
    cout<<endl;

    cout<<"BFS:\n";
    A.BFS(arr,vis2,1);

    cout<<endl;

    return 0;
}