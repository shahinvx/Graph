#include <bits/stdc++.h>
using namespace std;
// Function to isnert edges of tree
void insert(int x, int y, vector<int> adjacency[])
{
    adjacency[x].push_back(y);
}
// Function to run DFS on a tree
void dfs(int node, int leaf[], int vis[],
         vector<int> adjacency[])
{
    leaf[node] = 1;
    vis[node] = 1;

    // iterate on all the nodes
    // connected to node
    for (auto it : adjacency[node])
    {

        // If not visited
        if (!vis[it])
        {
            dfs(it, leaf, vis, adjacency);
            //leaf[node] += leaf[it];
        }
    }
    /// leaf node found
    cout<<adjacency[node].size()<<" size of "<<node<<endl;
    if (adjacency[node].size()==0)
        leaf[node] = adjacency[node].size();
}

// Function to print number of
// leaf nodes of a node
void printLeaf(int n, int leaf[])
{
    // Function to print leaf nodes
    for (int i = 1; i <= n; i++)
    {
        cout << "The node " << i << " has "
             << leaf[i] << " leaf nodes\n";
    }
}

// Driver Code
int main()
{
    int N, dist, from, to;

    cin>>N; // no of nodes
    vector<int> adjacency[N + 1]; // adjacency list for tree
    for(int i =1; i<N; i++)
    {
        cin>>from>>to;
        insert(from, to, adjacency);
    }
    int leaf[N + 1]; // Store count of leaf in subtree of i
    int vis[N + 1] = { 0 }; // mark nodes visited

    dfs(1, leaf, vis, adjacency);

    printLeaf(N, leaf);

    return 0;
}

