#include<iostream>
using namespace std;
int main()
{
    int arr[100][100]= {0};
    int row,column,edge,nodes;
    cin>>nodes>>edge;  /// nodes = node, edge = path

    while(edge--)
    {
        cin>>row>>column;
        arr[row-1][column-1] = 1;
    }
    for(int i=0; i<nodes; i++)
    {
        cout<<i+1<<"-> ";
        for(int j=0; j<nodes; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
