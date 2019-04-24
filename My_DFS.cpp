#include<bits/stdc++.h>
using namespace std;
vector <int> nodes[10000];
int apearing_t[10000];
int final_t[10000];
int color[10000];
int tim = 0;
void DFS(int source)
{
    vector <int> :: iterator it;
    int valueofQ = source;
    tim = tim + 1;
    apearing_t[valueofQ] = tim;
    color[valueofQ] = 1; /// 1,2,3 -> gray, white , black
    for(it = nodes[valueofQ].begin(); it!=nodes[valueofQ].end(); it++)
    {
        if(color[*it]==0)
        {
            DFS(*it);
        }
    }
    color[valueofQ]=2;
    tim = tim + 1;
    final_t[valueofQ] = tim;
}
void print(int node)
{
    for(int i=1; i<=node; i++)
    {
        cout<<"Apearing tim of "<<i<<": "<<apearing_t[i]<<endl;
    }
    for(int i=1; i<=node; i++)
    {
        cout<<"Finishing tim of "<<i<<": "<<final_t[i]<<endl;
    }
}
int main()
{
    int node, edge, from, to;
    int sourse;
    cin>>node>>edge;
    for(int i=1; i<=edge; i++)
    {
        cin>>from>>to;
        nodes[from].push_back(to);
        nodes[to].push_back(from);
    }
    cout<<"From Node : ";
    cin>>sourse;
    DFS(sourse);
    print(node);
    return 0;
}
