#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
vector<int>ver[1000000];
vector<int>ver1[1000000];
int cost[10000][10000];
int pre[100000];
int dis[100000];
int arr[100000];
void bfs(int s,int v)
{
    memset(dis,INF,sizeof(dis[0])*100000);
    memset(pre,-1,sizeof(pre[0])*100000);
    queue<int>q;
    vector<int>:: iterator it;
    q.push(s);
    dis[s]=0;
    pre[s]=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(it=ver[u].begin(); it!=ver[u].end(); it++)
        {
            /*if(pre[*it]==-1)
            {
                dis[*it]=dis[u]+cost[u][*it];
                pre[*it]=u;
                q.push(*it);
            }*/
            //cout<<dis[u]<<" "<<dis[*it]<<" "<<cost[u][*it]<<endl;
            if(dis[u]+cost[u][*it]<dis[*it])
            {
                //cout<<u<<" :"<<dis[u]<<" v:"<<*it<<" "<<cost[u][*it]<<endl;
                dis[*it]=dis[u]+cost[u][*it];
               // cout<<u<<" "<<*it<<endl;
                //cout<<dis[u]<<" "<<cost[u][*it]<<endl<<endl;
                pre[*it]=u;
                q.push(*it);
            }

        }
    }
    for(int i=1; i<=v; i++)
        cout<<"distance "<<s<<" to "<<i<<" = "<<dis[i]<<"\n";
    for(int i=1; i<=v; i++)
        cout<<"preious of "<<i<<" is "<<" = "<<pre[i]<<"\n";
    stack<int> path;
    ///&&pre[v]!=0
   // v=2;
    int ss=0;
    while(pre[v]!=1&&pre[v]!=0)
    {
        path.push(v);
        v=pre[v];
    }
    path.push(v);
    path.push(1);
    while(!path.empty()&&pre[v]!=0)
    {
        ss=ss+dis[path.top()];
        if(path.size()==1)
            cout<<path.top();
        else
            cout<<path.top()<<" ";
        path.pop();

    }
    cout<<endl<<ss;
}
int main()
{
    int v,e,c,s,d;
    cin>>v>>e;
    for(int i=0; i<e; i++)
    {
        cin>>s>>d>>c;
        ver[s].push_back(d);
        ver[d].push_back(s);
        cost[s][d]=c;
        cost[d][s]=c;
    }
    cout<<endl;
    bfs(1,v);
}

