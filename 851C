#include <bits/stdc++.h>
using namespace std;
 
struct data
{
    int a,b,c,d,e;
}points[1010];
 
vector< data > vectors[1010];
vector< int > ans;
 
int main ()
{
    int n; cin>>n;
    for(int i = 1; i<=n; i++)
    {
        int x,y,z,w,v;cin>>x>>y>>z>>w>>v;
        points[i].a = x;
        points[i].b = y;
        points[i].c = z;
        points[i].d = w;
        points[i].e = v;
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(i==j) continue;
            data dd;
            dd.a = points[j].a - points[i].a;
            dd.b = points[j].b - points[i].b;
            dd.c = points[j].c - points[i].c;
            dd.d = points[j].d - points[i].d;
            dd.e = points[j].e - points[i].e;
            vectors[i].push_back(dd);
        }
    }
    bool f;
 
    for(int xx = 1; xx<=n; xx++)
    {
        f = true;
        int nn = (int) vectors[xx].size();
        for(int i = 0; i<nn; i++)
        {
            if(!f) break;
            data X = vectors[xx][i];
            for(int j = i+1; j<nn; j++)
            {
                data Y = vectors[xx][j];
 
                if(((X.a*Y.a + X.b*Y.b + X.c*Y.c + X.d*Y.d + X.e*Y.e)/((sqrt(X.a*X.a + X.b*X.b + X.c*X.c + X.d*X.d + X.e*X.e))*(sqrt(Y.a*Y.a + Y.b*Y.b + Y.c*Y.c + Y.d*Y.d + Y.e*Y.e))))> 0 && ((X.a*Y.a + X.b*Y.b + X.c*Y.c + X.d*Y.d + X.e*Y.e)/((sqrt(X.a*X.a + X.b*X.b + X.c*X.c + X.d*X.d + X.e*X.e))*(sqrt(Y.a*Y.a + Y.b*Y.b + Y.c*Y.c + Y.d*Y.d + Y.e*Y.e)))) <=1)
                {
                    f = false;
                    break;
                }
            }
        }
        if(f) ans.push_back(xx);
    }
    cout<<(int)ans.size()<<endl;
    for(int i = 0; i< (int)ans.size(); i++) cout<<ans[i]<<endl;
    return 0;
}
