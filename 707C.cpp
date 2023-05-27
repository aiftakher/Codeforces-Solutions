#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main ()
{
    ll x; cin>>x;
    for(ll m = 1; m*m <=x; m++)
    {
        ll n  = x - m*m;
        n = sqrt(n);
        if(n*n + m*m == x)
        {
            //if(m==0 || n==0) continue;
            if(m!=0 && n!=0 && (ll)max(m,n)*max(m,n) - (ll)min(m,n)*min(m,n)!=0)
            {
                cout<<2*m*n<<" "<<(ll)max(m,n)*max(m,n) - (ll)min(m,n)*min(m,n)<<endl;
                return 0;
            }
        }
    }
    //cout<<"aa"<<endl;
    if(x%2==0)
    {
        ll xx = x/2;
        for(ll m = 1; m*m <=xx; m++)
        {
            if(xx%m==0)
            {
                ll n = xx/m;
                if(m==0 || n==0 || ((ll)max(m,n)*max(m,n) - (ll)min(m,n)*min(m,n))==0) continue;
                cout<<m*m + n*n<<" "<<(ll)max(m,n)*max(m,n) - (ll)min(m,n)*min(m,n)<<endl;
                return 0;
            }
        }
    }
    for(int i = 1; i*i<=x; i++)
    {
        if(x%i==0)
        {
            ll j = x/i;
            j+=i;
            if(j%2!=0) continue;
            ll m = j/2;
            j -=2*i;
            j = abs(j);
            if(j%2!=0) continue;
            ll n = j/2;
            if(m==0 || n==0) continue;
            cout<<(ll) 2*m*n<<" "<<(ll)m*m + n*n;
            return 0;
        }
    }
    cout<<-1; return 0;
}
