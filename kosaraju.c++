#include<bits/stdc++.h>
using namespace std;

void addedge(vector<vector<pair<int,int>>> &adj,int u,int v,int dis)
{
    adj[u].push_back({v,dis});
    // adj[v].push_back(u);
}

void printgraph(vector<vector<pair<int,int>>> &adj)
{
    int i=0;
    for(auto x: adj)
    {
        cout<<i<<" -> ";
        for( auto  l:x)
        {
            cout<< l.first<< " ,  "<< l.second<<" | ";
        }
        cout<<endl;
        ++i;
    }
}

void dfs1_rec(vector< vector<pair<int,int>>> &adj,stack<int> &seq_dfs,vector<bool> &visited,int u)
{
    visited[u]=true;

    for(auto x: adj[u])
    {
        int v=x.first;
        if(!visited[v])
            dfs1_rec(adj,seq_dfs,visited,v);
    }
    seq_dfs.push(u);
}


void dfs2_rec(vector< vector<pair<int,int>>> &adj,vector<bool> &visited,int u)
{
    visited[u]=true;
    cout<<u<<"  ";
    for( auto x: adj[u])
    {
        int v=x.first;
        if(!visited[v])
            dfs2_rec(adj,visited,v);
    }
}
void kosaraju(vector< vector<pair<int,int>>> &adj)
{
    // step 1
    stack<int>seq_dfs;
    int size=adj.size();
    vector<bool> visited(size,false);
    for(int i=0;i<size;i++)
    {
        if(!visited[i])
            dfs1_rec(adj,seq_dfs,visited,i);
    }
    // step 2
    vector< vector<pair<int,int>> >adj2(size);
    for(int i=0;i<size;i++)
    {
        for(auto v: adj[i])
        {
            addedge(adj2,v.first,i,v.second);
        }
    }
    printgraph(adj2);
    cout<<endl;
    
    // step 3
    visited.assign(size,false);
    while(!seq_dfs.empty())
    {
        int v=seq_dfs.top();
        seq_dfs.pop();
        if(!visited[v])
        {
            dfs2_rec(adj2,visited,v);
            cout<<endl;
        }
    }

}
int main()
{
    int size=5;
    vector< vector<pair<int,int>> >adj(size);
    addedge(adj,0,1,2);
    addedge(adj,1,2,3);
    addedge(adj,2,0,1);
    addedge(adj,3,1,2);
    addedge(adj,3,4,4);
    
    stack<int>seq_dfs;
    kosaraju(adj);
    cout<<endl;
    printgraph(adj);
    return 0;
}