#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define pb push_back
#define mp make_pair
ll nn,mm;
 
struct node
{
    ll n, cost;
    node(ll _n, ll _cost)
    {
        n = _n;
        cost = _cost;
    }
};
 
bool operator < (const node a, const node b)
{
    return a.cost > b.cost;
}
 
vector < pair<ll,ll> > graph[100010];
ll path[100010];
ll dist[100010];
vector<ll> pathh;
priority_queue<node> PQ;
 
void dijkstra(int s)
{
    for(int i = 0; i<100010; i++) dist[i] = (ll)1e16; path[1] = 0;
    dist[s] = 0;
    PQ.push(node(s,0));
    while(!PQ.empty())
    {
        node ss = PQ.top(); PQ.pop();
        ll uu = ss.n;
        for(ll i = 0; i< graph[uu].size(); i++)
        {
            int vv = graph[uu][i].first;
            int ecost = graph[uu][i].second;
            if(dist[vv] > dist[uu] + ecost)
            {
                dist[vv] = dist[uu] + ecost;
                PQ.push(node(vv, dist[vv]));
                path[vv] = uu;
            }
        }
    }
}
 
int main ()
{
    cin>>nn>>mm;
    for(int i = 1; i<=mm; i++)
    {
        ll u,v,cost; cin>>u>>v>>cost;
        graph[u].pb(mp(v,cost));
        graph[v].pb(mp(u,cost));
    }
    dijkstra(1);
    if(dist[nn] == (ll)1e16) cout<<-1;
    else
    {
        pathh.push_back(nn);
        ll ss = nn;
        while(path[ss]!=0)
        {
            pathh.push_back(path[ss]);
            ss = path[ss];
        }
        for(ll i = pathh.size()-1; i>=0; i--) cout<<pathh[i]<<" ";
    }
    return 0;
}
