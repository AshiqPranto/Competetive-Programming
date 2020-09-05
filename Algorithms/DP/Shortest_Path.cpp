/* © Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/

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
#include <stack>
#include<queue>
#include<deque>

#define ll long long
#define ld long double
#define pb(x) push_back(x)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define PI (2*acos(0.0))
#define sqr(x) ((x)*(x))
#define FOR(start,end) for(ll i=start;i<=end;i++)
#define readfile freopen("input.txt","r",stdin);
#define writefile freopen("output.txt","w",stdout);
#define mx 200
#define inf 1000000

using namespace std;

ll weight[mx][mx],mem[mx];

ll f(ll u,ll n)
{
    if(u==n-1) return 0;
    else if(mem[u]!=inf) return mem[u];
    else
    {
        ll ans=inf;
        for(ll i=0;i<n;i++)
        {
            if(weight[u][i]!=0)
            {
                ans=min(ans,f(i,n)+weight[u][i]);
            }
        }
        mem[u]=ans;
        return ans;
    }
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,u,v,w;
    cin>>n>>m;
    for(ll i=0;i<mx;i++)
    {
        mem[i]=inf;
    }
    while(m--)
    {
        cin>>u>>v>>w;
        weight[u][v]=w;
    }
    cout<<f(0,n)<<endl;
}
/*
INPUT:
5 6
0 1 2
0 3 1
3 1 3
1 2 1
1 4 9
2 4 3
*/
