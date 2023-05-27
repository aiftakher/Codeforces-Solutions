#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef map<string,string> mss;
typedef map<int, vector<int> > mvii;
typedef map<int, int> mii;
typedef queue <int> qi;
typedef map <int, vector<string> > mvis;
typedef map <string, vector<int> > mvsi;
typedef vector <string> vs;
typedef pair <int, int> pii;
 
// Order Statistic Tree
 
/* Special functions:
 
		find_by_order(val) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define INF 2000000000
#define pb push_back
#define MAX 100002
#define debug cout<<"A"<<"\n"
#define prnt(a) cout<<a<<"\n"
#define mod 1000000007LL
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=b; i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define lc ((node)<<1)
#define rc ((node)<<1|1)
#define VecPrnt(v) FOR(j,0,v.size()) cout<<v[j]<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
 
 
/* Direction Array */
 
// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};
 
template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
 
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
int setbit(int N,int pos){return N=N | (1<<pos);}
int resetbit(int N,int pos){return N= N & ~(1<<pos);}
bool getbit(int N,int pos){return (bool)(N & (1<<pos));}
inline ll power(ll a, ll b)
{
	ll multiply=1;
	FOR(i,0,b)
	{
		multiply*=a;
	}
	return multiply;
}
 
/****** END OF HEADER ******/
 
int mat[55][55];
 
 
int main ()
{
    int n; cin>>n;
    int ss = 1, D = n/2; D--;
    ms(mat,0);
    for(int i = 1, l = 2; i<= n/2; i++, l++ , D--)
    {
        //cout<<i<<" "<<2*D+1<<endl;
        for(int rep = 1, j = l ; rep <= 2*D + 1; rep++, j++)
        {
            mat[i][j] = ss; ss+=2;
        }
    }
    for(int j = 1; j<=n; j++)
    {
        mat[n/2 + 1][j] = ss; ss+=2;
    }
    D = 0;
 
    for(int i = n/2 + 2, l = n/2 + 1 ; i<= n; i++, l-- , D++)
    {
        //cout<<i<<" "<<2*D+1<<endl;
        for(int rep = 1, j = l ; rep <= 2*D + 1; rep++, j++)
        {
            mat[i][j] = ss; ss+=2;
        }
    }
 
    ss = 2;
    FOR(i,1,n+1)
    {
        FOR(j,1,n+1)
        {
            if(mat[i][j] ==0)
            {
                mat[i][j] = ss; ss+=2;
            }
        }
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
 
    return 0;
}
