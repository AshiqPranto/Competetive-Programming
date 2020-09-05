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
#include<stack>
#include<queue>
#include<deque>

//#include<bits/stdc++.h>

#define ll long long
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
#define readfile freopen("input.txt","r",stdin);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mx 10009
#define inf (ll)1e9
#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

ll fx[4]={-1,+1,0,0},fy[4]={0,0,+1,-1};
ll k,n,m,ans[mx],cnt,visit[mx];
vector<ll>edges[mx];

void bfs(ll x)
{
    ans[x]++;
    //if(ans[x]==k) cnt++;
    memset(visit,0,sizeof visit);
    queue<ll>q;
    q.emplace(x);
    visit[x]=1;
    while(!q.empty())
    {
        ll top=q.front();
        //cout<<top<<" ";
        q.pop();
        for(ll i=0;i<edges[top].size();i++)
        {
            if(visit[edges[top][i]]==0)
            {
                q.emplace(edges[top][i]);
                visit[edges[top][i]]=1;
                ans[edges[top][i]]++;
                //cout<<ans[edges[top][i]]<<endl;
                //if(ans[edges[top][i]]>=k) cnt++;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //readfile
    ll test,u,v,forBfs[mx];
    scanf("%lld",&test);
    for(ll t=1;t<=test;t++)
    {

        scanf("%lld %lld %lld",&k,&n,&m);
        for(ll i=1;i<=k;i++) scanf("%lld",&forBfs[i]);

        memset(ans,0,sizeof ans);
        for(ll i=1;i<=m;i++)
        {
            scanf("%lld %lld",&u,&v);
            edges[u].pb(v);
        }

        cnt=0;
        for(ll i=1;i<=k;i++)
        {
            bfs(forBfs[i]);
        }
        for(ll i=1;i<=n;i++)
        {
            if(ans[i]>=k) cnt++;
        }

        printf("Case %lld: %lld\n",t,cnt);
        for(ll i=0;i<=n;i++)
        {
            edges[i].clear();
        }

    }
}
