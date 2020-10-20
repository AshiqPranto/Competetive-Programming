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
#define mod 10056
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
ll dp[1005],nCr[1005][1005];

ll calculate(ll n)
{
    if(dp[n]!=-1) return dp[n];
    ll temp = 0;
    for(ll i=1;i<=n;i++)
    {
        temp+= (nCr[n][i]*(calculate(n-i)%mod))%mod;
        temp%=mod;
    }
    dp[n] = temp;
    return dp[n] ; 
}

void eff()
{
    ll n;
    sfl(n);
    dp[0]=1;
    dp[1]=1;
    printf("%lld\n",dp[n]);
}

void calnCr()
{
    nCr[1][1]=1;
    nCr[1][0]=1;
    for(ll i=2;i<1004;i++)
    {
        nCr[i][0] = 1;
        nCr[i][i] = 1;
        for(ll j=1;j<i;j++)
        {
            nCr[i][j] = nCr[i-1][j]%mod + nCr[i-1][j-1]%mod;
            nCr[i][j]%=mod;
        }
    }
}

int main()
{
    //fastio
    ll test ;
    sfl(test);
    calnCr();
    memset(dp,-1,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    calculate(1000);
    for(ll i=0;i<test;i++)
    {
        printf("Case %lld: ",i+1);
        eff();
        /* code */
    }
    
    return 0;
}