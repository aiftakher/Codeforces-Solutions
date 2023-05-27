#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
int main ()
{
    ll n,a,b,p,q; cin>>n>>a>>b>>p>>q;
    ll GCD = __gcd(a,b);
    ll lcm = (ll)(a*b)/GCD;
    ll z = (ll) (n/lcm);
    ll x = (n/a - z);
    ll y = (n/b - z);
 
    cout<< (ll) x * p + y * q + z * max(p,q);
    return 0;
}
