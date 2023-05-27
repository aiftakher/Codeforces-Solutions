// https://codeforces.com/contest/791/problem/C

#include <bits/stdc++.h>
using namespace std;
 
vector< string > names;
 
void Generate()
{
    string str = "";
 
    for(char i = 'a'; i<='z'; i++)
    {
        str = ""; str +=i;
        for(char j = 'a'; j<='z'; j++)
        {
            str+=j;
            names.push_back(str);
            str = ""; str +=i;
        }
    }
}
 
vector< string > res;
int main ()
{
    Generate();
    int n,k; cin>>n>>k;
    res.push_back("blabla");
    for(int i = 0; i<n; i++)
    {
 
        res.push_back(names[i]);
    }
   // for(int i = 1; i<=n; i++) cout<<res[i]<<" ";
 
 
    int start = n;
 
    string s;
    for(int l = 1; l<= n - k + 1; l++)
    {
        cin>>s;
        if(s=="NO")
        {
            res[l + k - 1] = res[l];
            //cout<<res[l + k - 1];
            //break;
        }
 
    }
    for(int i = 1; i<=n; i++)
    {
        res[i][0] = toupper(res[i][0]);
        cout<<res[i]<<" ";
    }
 
    return 0;
}
