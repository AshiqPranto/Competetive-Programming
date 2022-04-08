/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
#include<bits/stdc++.h>
 
#define ll long long
#define ld long double
#define FOR(x,y) for(ll i=x;i<=y;i++)
#define f0(x) for(ll i = 0;i<=x;i++)
#define f1(x) for(ll i = 1;i<=x;i++)
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
#define mx 10005
#define inf (ll)1e17
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
 
vector<int>adj[mx];
int low[mx];
int parent[mx];
int d[mx];
int articulation_points[mx];
int timee = -1;

void find_articulation_point(int u)
{
    int child_count = 0;
    d[u] = timee; 
    low[u] = timee;
    timee++;
    for(int child_node: adj[u])
    {
        if(d[child_node] == -1)
        {
            parent[child_node] = u;
            child_count++;
            find_articulation_point(child_node);
            low[u] = min(low[u],low[child_node]);

            if(parent[u]==-1 && child_count>1) articulation_points[u] = 1;
            else if(parent[u]!=-1 && d[u]<=low[child_node]) articulation_points[u] = 1;

        }
        else if (parent[u] != child_node)
        {
            low[u] = min(low[u],d[child_node]);
        }
    }
}

void eff()
{
    int n,m,u,v;
    sff(n,m);
    for(int i = 0;i<mx;i++)
    {
        adj[i].clear();
        parent[i] = -1;
        low[i] = -1;
        d[i] = -1;
        articulation_points[i] = 0;
    }
    while (m--)
    {
        sff(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // cout<<"ap 1 = "<<articulation_points[1]<<endl;
    timee = 1;
    find_articulation_point(u);

    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        // cout<<"i = "<<i<<" -> "<<articulation_points[i]<<endl;
        if(articulation_points[i] ==1)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
 
int main()
{
    // fastio
    ll test = 1;
    sfl(test);
    for(ll i=0;i<test;i++)
    {
        printf("Case %lld: ",i+1);
        eff();
    }
//    cout<<check(81);
    return 0;
}