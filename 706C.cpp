#include <bits/stdc++.h>
using namespace std;
 
 
string rev( string u)
{
    string v;
    reverse(u.begin(), u.end());
    return u;
}
 
 
 
bool check(string u, string v)
{
    for(int i = 0; i<min(v,u).size(); i++)
    {
        if(v[i] > u[i]) return true;
        else if(v[i] < u[i]) return false;
        else continue;
    }
    return v.size() >= u.size();
}
 
int C[100010];
 
 
 
long long dp[100010][2];
vector< string > vv;
 
int main ()
{
    int n; cin>>n;
    for(int i = 0; i<n; i++) cin>>C[i];
    for(int i = 1; i<=n; i++)
    {
        string ss; cin>>ss; vv.push_back(ss);
    }
    for(int i = 0; i<100010; i++)
    {
        for(int j = 0; j<2; j++) dp[i][j] = (long long) 1e16;
    }
    dp[0][0] = 0;
    dp[0][1] = C[0];
    for(int i = 1; i<n; i++)
    {
        if(check(vv[i-1], vv[i]))
        {
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        }
        if(check(rev(vv[i-1]), vv[i]))
        {
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }
        if(check(rev(vv[i-1]), rev(vv[i])))
        {
            dp[i][1] = min(dp[i][1], dp[i-1][1] + C[i]);
        }
        if(check(vv[i-1], rev(vv[i])))
        {
            dp[i][1] = min(dp[i][1], dp[i-1][0] + C[i]);
        }
    }
    if(dp[n-1][0]== (long long) 1e16 && dp[n-1][1] == (long long) 1e16)
    {
        cout<<-1;
    }
    else
    {
        cout<< min(dp[n-1][0], dp[n-1][1]);
    }
    return 0;
}
