// https://codeforces.com/contest/785/problem/C

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
int main ()
{
    ll n, m; cin>>n>>m;
 
    if(n<=m)
    {
        cout<<n<<endl;
        return 0;
 
    }
    ll tot = m;
 
    n = n - m;
 
    ll lo = 0LL, hi = 2234567890LL;
 
    ll cache;
    while(lo <= hi)
    {
        ll x = (lo + hi)/2LL;
 
        ll res = (ll)( x * (x+1LL)) / 2LL;
 
        if(res == n)
        {
            cout<<tot + x<<endl;
            return 0;
        }
        else if(res > n)
        {
            hi = x - 1LL;
        }
        else if(res < n)
        {
          cache = x;
          lo = x + 1LL;
        }
    }
 
    cout<< tot + cache + 1 <<endl;
    return 0;
 
}
