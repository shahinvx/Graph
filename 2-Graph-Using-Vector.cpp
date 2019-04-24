#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex,edge,source,destination;
    cin>>vertex>>edge;
    vector <int> vec[vertex];

    while(edge--)
    {
        cin>>source>>destination;
        vec[source].push_back(destination);
    }
//    cout<<vec.size()<<endl;
    for(int i=0; i<vertex; i++)
    {
        int s=vec[i].size();
        cout<<"Vertex of "<<i<<": ";
        for(int j=0; j<s; j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
