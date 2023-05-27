#include <bits/stdc++.h>
using namespace std;
 
const int N = 5010;
 
int n;
int val[N];
int arr[N];
int last[N];
int dp[N];
 
 
inline int func(int i)
{
    if(i>=n) return 0;
    if(dp[i]!= -1) return dp[i];
    int dummy = last[arr[i]];
    for(int j = i; j<=dummy; j++)
    {
        if(last[arr[j]] > dummy) dummy = last[arr[j]];
    }
    int ans = 0;
    bool ok = true;
    for(int j = i; j<=dummy; j++)
    {
        if(val[j] == -1)
        {
            ok = false; break;
        }
    }
 
    if(!ok)
    {
        val[i] = -1;
        for(int j = i; j<n; j++)
        {
                if(arr[j]==arr[i]) val[j] = -1;
        }
        ans = max(ans, func(i+1));
    }
    else
    {
        int xorsum = arr[i];
        map<int,bool> vis; vis[arr[i]] = 1;
        for(int j = i+1; j<=dummy; j++)
        {
            if(!vis[arr[j]])
            {
                xorsum ^= arr[j];
                vis[arr[j]] = true;
            }
        }
        ans = max(ans, xorsum + func(dummy + 1));
        val[i] = -1;
        for(int j = i; j<n; j++)
        {
            if(arr[j]==arr[i]) val[j] = -1;
        }
        ans = max(ans, func(i+1));
    }
    return dp[i] = ans;
}
 
 
int main ()
{
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
        last[arr[i]] = i;
    }
    memset(dp, -1 , sizeof dp );
    memset(val, 1, sizeof val);
 
    cout<< func(0) <<endl;
    return 0;
 
}
