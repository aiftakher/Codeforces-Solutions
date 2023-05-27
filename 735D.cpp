// https://codeforces.com/contest/735/problem/D

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n; cin>>n;
    if(n >2 && n%2==0)
    {
        cout<< 2; return 0;
    }
    bool prime = true;
    for(int i = 2; i*i <=n ; i++)
    {
        if(n%i==0)
        {
            prime = false; break;
        }
    }
    if(prime)
    {
        cout<<1; return 0;
    }
    int m = n-2;
    prime = true;
    for(int i = 2; i*i <=m ; i++)
    {
        if(m%i==0)
        {
            prime = false; break;
        }
    }
    if(prime) cout<<2;
    else cout<<3;
    return 0;
}
