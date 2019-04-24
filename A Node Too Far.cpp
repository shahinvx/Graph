#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
int source, node, edge, from, to, vst_nd=0, cas;
void BFS(int source, int dist, map <int,vector<int> > nodes)
{
    //int distanc[1000]={0};
    map<int,int> distanc;
    //bool visited[1000]={0};
    map<int,bool> visited;
    //int previous[1000]={-1};
    map<int,int> previous;
    queue <int> q;
    int cnt = 0, inside=0;
    distanc[source]=0;
    visited[source]=true;
    q.push(source);
    int siz = nodes.size();
    vector <int> :: iterator it;
    while(!q.empty())
    {
        vst_nd++;
        int valueofQ = q.front();
        for(it=nodes[valueofQ].begin(); it!=nodes[valueofQ].end(); it++)
        {
            inside++;

            if(visited[*it]==false)
            {
                visited[*it]=true;
                distanc[*it]=distanc[valueofQ]+1;
                //cout<<distanc[*it]<<" : inside distance "<<endl;
                if(distanc[*it]<=dist)
                {
                    cnt++;
                }
                previous[*it]=valueofQ;
                q.push(*it);
            }
        }
        q.pop();
    }
    //cout<<vst_nd<<" visited node "<<cnt<<endl;
    cas++;
    if(inside!=0){
    cnt = siz - cnt - 1;
    }else{cnt = siz;}
    cout<<"Case "<<cas<<": "<<cnt<<" nodes not reachable from node "<<source<<" with TTL = "<<dist<<"."<<endl;
    vst_nd = 0;
}
int main()
{
    int k = 1, m = 1, dist;
    while(k)
    {
        //cout<<" take ";
        cin>>edge;
        if(edge!=0)
        {
            map <int,vector<int> > nodes;
            //vector <int> nodes[1000];
            for(int i=1; i<=edge; i++)
            {
                cin>>from>>to;
                //cout<<from<<" "<<to<<" f t "<<endl;
                nodes[from].push_back(to);
                nodes[to].push_back(from);
            }
            while(m)
            {
                cin>>source>>dist;
                //cout<<source<<" "<<dist<<" s d "<<endl;
                if(source == 0 && dist==0)
                {
                    break;
                }
                else
                {
                    BFS(source, dist, nodes);
                }
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

