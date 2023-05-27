#include <bits/stdc++.h>
using namespace std;
 
int vis[100010];
vector< pair<int,int> > graph[100010];
int val[100010],n,cnt;
void dfs2(int u)
{
    vis[u] = 2; cnt++;
    for(int i = 0; i<graph[u].size(); i++)
    {
        if(vis[graph[u][i].first]==0) dfs2(graph[u][i].first);
    }
}
 
void dfs(int u, int sum)
{
    vis[u] = 1;
    for(int i = 0; i<graph[u].size(); i++)
    {
        int v = graph[u][i].first, cost = graph[u][i].second;
        if(vis[v]) continue;
        if(sum + cost > val[v] && vis[v]==0)
        {
            //cnt++;
            //cout<< v<<" "<< sum + cost<<endl;
            dfs2(v);
        }
        else if(vis[v]==0)
        {
            dfs(v,max(0,sum+cost));
 
        }
    }
    vis[u]=2;
}
 
 
int main ()
{
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>val[i];
    for(int i = 1; i<=n-1; i++)
    {
        int p,c; cin>>p>>c;
        graph[i+1].push_back(make_pair(p,c));
        graph[p].push_back(make_pair(i+1,c));
    }
    memset(vis, 0, sizeof vis);
    cnt = 0; dfs(1,0); cout<<cnt<<endl;
}
