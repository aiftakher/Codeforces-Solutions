// https://codeforces.com/contest/854/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXX = 600010;
bool vis[MAXX];
int res[MAXX];
 
inline bool srt(pair< int, int > a, pair<int,int> b)
{
    if(a.first != b.first) return a.first > b.first;
    else return a.first < b.first;
}
 
vector< pair<ll,ll> > v;
 
int main ()
{
    ll n,k,cost; cin>>n>>k;
    for(ll i = 1; i<=n; i++)
    {
        cin>>cost;
        v.push_back(make_pair(cost,i));
    }
    sort(v.begin(),v.end(),srt);
    memset(vis, false, sizeof vis);
    int beg = k + 1; ll ans = 0LL;
    for(int  i = 0; i<n; i++)
    {
        int id = v[i].second;
        if(!vis[id] && id >= beg)
        {
            vis[id] = true;
            res[id] = id;
        }
        else
        {
            while(vis[beg])
            {
                beg++;
            }
            vis[beg] = true;
            ans +=(ll)( (ll)(abs(id - beg)) * (ll)v[i].first);
            res[id] = beg;
            beg++;
        }
 
 
    }
    cout<<ans<<endl;
    for(int i = 1; i<=n; i++) cout<<res[i]<<" ";
    return 0;
}
