/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
#include<bits/stdc++.h>
 
#define ll long long
#define ld long double
#define FOR(x,y) for(ll i=x;i<=y;i++)
#define pb(x) push_back(x)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define matrix(x) vector<vector<x>>
#define vss vector<string>
#define PI (2*acos(0.0))
#define sqr(x) ((x)*(x))
#define sf(a)   scanf("%d",&a)
#define sfl(a)  scanf("%lld",&a)
#define sff(a,b)    scanf("%d %d",&a,&b)
#define sffl(a,b)   scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define ms(a,b) memset(a, b, sizeof(a))
#define ff  first
#define ss  second
#define lcm(a, b)   ((a)*((b)/__gcd(a,b)))
#define all(a)  a.begin(),a.end()
#define readfile freopen("input.txt","r",stdin);
#define writefile freopen("output.txt","w",stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define gap " "
#define mx 104
#define inf (ll)1e9
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define EMPTY_VALUE -1
#define mod 1000000007
#define MOD(a,b) (a%b + b)%b
 
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll n,k,a[100005][4],dp[100005][4];

ll minimum(ll x,ll prev)
{
    if(x>n)
    {
        return 0;
    }
    if(x==n)
    {
        ll maxi = -inf;
        for(ll i=1;i<=3;i++)
        {
            if(i!=prev)
                maxi = max(maxi,a[x][i]);
        }
        return maxi;
    }
    if(dp[x][prev]!=-1)
    {
        return dp[x][prev];
    }
    ll maxi = -inf;
    for(ll i=1;i<=3;i++)
    {
        if(i!=prev)
        {
            maxi = max(maxi,a[x][i]+minimum(x+1,i));
        }
    }
    return dp[x][prev] = maxi;
}

void eff()
{
    memset(dp,-1,sizeof(dp));
    sfl(n);
    for(ll i=1;i<=n;i++)
    {
        sfffl(a[i][1],a[i][2],a[i][3]);
    }
    ll ans = -inf;
    for(ll i=1;i<=3;i++)
    {
        ans = max(ans,a[1][i]+minimum(2,i));
    }
    cout<<ans<<endl;
}
 
int main()
{
    // fastio
    // ll test ;
    // sfl(test);
    // for(ll i=0;i<test;i++)
    // {
        // printf("Case %lld: ",i+1);
        eff();
    // }
//    cout<<check(81);
    return 0;
}
