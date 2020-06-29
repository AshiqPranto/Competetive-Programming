/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
// problem link: https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include<stdio.h>
#include<cmath>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<string.h>
#include<stack>
#include<queue>
#include<deque>

#define ll long long int
#define ld long double
#define FOR(x,y) for(ll i=x;i<=y;i++)
#define pb(x) push_back(x)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
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
#define mod 100000007

using namespace std;

vector<vector<ll>> graph;
vll dp;
vll numofchild;
ll ans=0;
void dfs(ll src,ll par=-1)
{
    dp[src]=0;
    numofchild[src]=1;
    for(ll child : graph[src])
    {
        if(child==par) continue;
        dfs(child,src);
        dp[src]+=dp[child];
        numofchild[src]+=numofchild[child];
    }
    dp[src]+=numofchild[src];
}

void tree_rerooting(ll src,ll par=-1)
{
    ans = max(ans,dp[src]);
    for(ll child : graph[src])
    {
        //remove source as a root
        if(child == par) continue;
        dp[src]-=dp[child];
        numofchild[src]-=numofchild[child];
        dp[src]-=numofchild[child];
        //add child as a root
        dp[child]+=dp[src];
        numofchild[child]+=numofchild[src];
        dp[child]+=numofchild[src];
        tree_rerooting(child,src);
        //add source again as a root
        dp[child]-=dp[src];
        numofchild[child]-=numofchild[src];
        dp[child]-=numofchild[src];

        dp[src]+=dp[child];
        numofchild[src]+=numofchild[child];
        dp[src]+=numofchild[child];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //readfile
    ll test,u,v;
    sfl(test);
    graph.resize(test+1);
    dp.resize(test+1);
    numofchild.resize(test+1);
    for(ll i=0;i<test-1;i++)
    {
        sffl(u,v);
        u--;
        v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(0);
    tree_rerooting(0);
    cout<<ans<<endl;
    return 0;
}



