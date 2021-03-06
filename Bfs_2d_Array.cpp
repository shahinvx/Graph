#include<iostream>
#include<bits/stdc++.h>
#define pr pair<int, int>
#define clear(a) memset(a, 0, sizeof(a))
using namespace std;
bool visited[100];
int arr[100][100]= {0};
int previous[100];
int distanc[100];
queue <pr> qq;
void bfs_2d(int x, int y, int nodes)
{
    previous[x] = 0;
    clear(visited);
    visited[x] = true;
    distanc[y] = 1;
    //q.push(pr(x,y));
    distanc[x];
    queue <int> q;
    q.push(x);
    q.push(y);
    cout<<endl;
    while(!q.empty())
    {
        int valueofQ = q.front();
        int i = valueofQ;
        //for(int i=valueofQ; i<=nodes; i++)
        //{
        for(int j=1; j<=nodes; j++)
        {
            //cout<<i<<" "<<j<<" value "<<endl;
            if(arr[i][j]==1 && visited[j]==false)
            {
                visited[j] = true;
                cout<<i<<" "<<j<<" i j "<<endl;
                distanc[j] = distanc[i]+1;
                previous[j] = i;
                q.push(j);
            }
        }
        //}
        q.pop();
    }
    cout<<"\nPrevious node : ";
    for(int i=1; i<=nodes; i++)
    {
        cout<<previous[i]<<" ";
    }
    cout<<endl;
    cout<<"\nDistance/Level : ";
    for(int i=1; i<=nodes; i++)
    {
        cout<<distanc[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    int row,column,edge,nodes;
    cin>>nodes>>edge;  /// nodes = node, edge = path

    while(edge--)
    {
        cin>>row>>column;
        arr[row][column] = 1;
        arr[column][row] = 1;
    }

    int x,y;
    cin>>x>>y;
    bfs_2d(x,y,nodes);

    for(int i=1; i<=nodes; i++)
    {
        cout<<i<<"-> ";
        for(int j=1; j<=nodes; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
