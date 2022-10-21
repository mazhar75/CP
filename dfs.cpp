#include<iostream>
#include<vector>
#define sz 1000
using namespace std;
vector<int>adj[sz];
bool vis[sz];
int arrived[sz];
int depurture[sz];
int curtime=0;
void dfs(int node)
{
    if(vis[node])return;
    vis[node]=true;
    curtime=curtime+1;
    arrived[node]=curtime;
    for(int i=0; i<adj[node].size(); i++)
    {
        if(!vis[adj[node][i]])dfs(adj[node][i]);
    }
    curtime=curtime+1;
    depurture[node]=curtime;
}
void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        arrived[i]=0;
        depurture[i]=0;
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    init(n);
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i=1; i<=n; i++)
    {
        cout<<"node #"<<i<<" :"<<"starting time="<<arrived[i]<<" "<<"Ending time="<<depurture[i]<<endl;
    }
    return 0;

}
