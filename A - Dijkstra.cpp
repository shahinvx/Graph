#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
vector<long long int>nodes[1000005];
typedef pair<long long int, long long int> pii;
map <long long int, map<long long int,long long int> > cost;
//long long int cost[10000][10000];
long long int previous[1000005];
long long int distanc[1000005];
long long int arr[1000005];
void bfs(long long int source,long long int node)
{
//    memset(distanc,INF,sizeof(distanc[0])*100000);
//    memset(previous,-1,sizeof(previous[0])*100000);
    //queue<long long int>q;
    for(long long int i=0; i<=1000005; i++){distanc[i]=INF;}
    for(long long int i=0; i<=1000005; i++){previous[i]=-1;}
    priority_queue<pii, vector<pii>, greater<pii> >q;
    vector<long long int>:: iterator it;
    q.push({0,source});
    distanc[source]=0;
    previous[source]=-1;
    long long int  store = node;
    long long int j=0;
    while(!q.empty())
    {
        long long int valueofq=q.top().second;
        for(it=nodes[valueofq].begin(); it!=nodes[valueofq].end(); it++)
        {
            if(distanc[valueofq]+cost[valueofq][*it]<distanc[*it])
            {
                distanc[*it]=distanc[valueofq]+cost[valueofq][*it];
                previous[*it]=valueofq;
                //cout<<*it<<" for "<<previous[*it]<<endl;
                q.push({distanc[*it], *it});
            }
        }
        q.pop();
    }
    if(distanc[node]==INF){cout<<-1<<endl;}
    else{
    long long int i=0;
    arr[i]=store;
    i++;
    while(previous[node]!=-1)
    {
        arr[i] = previous[node];
        i++;
        node = previous[node];
    }
    for(long long int j=i-1; j>=0; j--)
    {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    }
    //while(nodes[source].begin())
}
int main()
{
    long long int edge,c,s,d, node;
    cin>>node>>edge;
    for(long long int i=0; i<edge; i++)
    {
        cin>>s>>d>>c;
        nodes[s].push_back(d);
        nodes[d].push_back(s);
        cost[s][d]=c;
        cost[d][s]=c;
    }
    bfs(1,node);
}
