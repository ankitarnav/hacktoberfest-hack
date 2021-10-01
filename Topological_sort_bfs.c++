#include<bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>> &adj,int u,int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void printgraph(vector<vector<int>>&adj)
{
    int i=0;
    for(auto x: adj)
    {
        cout<<i<<" -> ";
        for( auto  l:x)
        {
            cout<< l<<" | ";
        }
        cout<<endl;
        ++i;
    }
}

void bfs_topo(vector<vector<int>>&adj,int size)
{
    vector<int> indegree(size,0);
    for(int i=0;i<size;i++)
    {
        for(int x:adj[i])
            indegree[x]++;
    }
    queue<int> q;
    for(int i=0;i<size;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto x: adj[u])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
    }
}


int main()
{
    int size=5;
    vector<vector<int>>adj(size);
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,2,3);
    addedge(adj,1,3);
    addedge(adj,1,4);
    bfs_topo(adj,size);
    return 0;
}