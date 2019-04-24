#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector <int> nodes[1000];
queue <int> q;
int source, node, edge, from, to;
int distanc[1000];
bool visited[1000];
int previous[1000]={-1}; /// all the previous node initialize to -1
void BFS(int source)
{
    distanc[source]=0; /// from given node/vertex distance/level is 0
    visited[source]=true; /// given node is need to visit
    q.push(source);       /// given value/node/vertex need to push to the queue

    vector <int> :: iterator it;
    while(!q.empty())
    {
        int valueofQ = q.front(); /// value of the queue is initialize
        /// nodes[valueofQ].begin() is the front of the initial node or queue
        /// nodes[valueofQ].end() end after the possible node to be visited from initialize
        for(it=nodes[valueofQ].begin(); it!=nodes[valueofQ].end(); it++)
        {
            /// after the valueofQ every visited[*it] will be false till end
            if(visited[*it]==false)
            {
                visited[*it]=true; /// node now visited so initialize with true
                /// calculate and store the distance of particular nodes from the valueofQ
                distanc[*it]=distanc[valueofQ]+1;
                /// store the parent node of the visited node
                previous[*it]=valueofQ;
                /// now push the next node into queue
                q.push(*it);
            }
        }
        /// after all work done for the front of the queue value/node/vertex
        /// the vertex/node need to be pop
        q.pop();
    }
    cout<<"Nodes : ";
    for(int i=1; i<=node; i++)
    {
        cout<<i<<" ";
    }
    cout<<"\nDistance/Level : ";
    for(int i=1; i<=node; i++)
    {
        cout<<distanc[i]<<" ";
    }
    cout<<"\nPrevious node : ";
    for(int i=1; i<=node; i++)
    {
        cout<<previous[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    cout<<"Nodes and Edge: ";
    cin>>node>>edge;
    //nodes[1000] = {0};
    for(int i=1; i<=edge; i++)
    {
        cin>>from>>to;
        nodes[from].push_back(to);
        nodes[to].push_back(from);
    }
    cout<<"From where to visit: ";
    cin>>source;
    BFS(source);
    return 0;
}
