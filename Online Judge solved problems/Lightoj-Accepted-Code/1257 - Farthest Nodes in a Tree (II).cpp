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
#define mx 30009
#define inf (ll)1e9
#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

ll fx[4]={-1,+1,0,0},fy[4]={0,0,+1,-1};
ll n,dis[mx],dis1[mx],visit[mx];
vector<pll>edges[mx];

void init()
{
    for(ll i=0;i<=n;i++)
    {
        visit[i]=0;
        dis[i]=0;
        dis1[i]=0;
    }
}

ll BFS(ll source)
{
    ll maximum=0,index;
    visit[source]=1;
    queue<ll>q;
    q.emplace(source);
    dis[source]=0;
    while(!q.empty())
    {
        ll top=q.front();
        q.pop();
        for(ll i=0;i<edges[top].size();i++)
        {
            if(visit[edges[top][i].first]==0)
            {
                q.push(edges[top][i].first);
                visit[edges[top][i].first]=1;
                dis[edges[top][i].first]=dis[top]+edges[top][i].second;
                if(dis[edges[top][i].first]>maximum)
                {
                    maximum=dis[edges[top][i].first];
                    index=edges[top][i].first;
                }
            }
        }

    }
    return index;
}

void BFS1(ll source)
{
    memset(visit,0,sizeof visit);
    visit[source]=1;
    queue<ll>q;
    q.emplace(source);
    dis1[source]=0;
    while(!q.empty())
    {
        ll top=q.front();
        q.pop();
        for(ll i=0;i<edges[top].size();i++)
        {
            if(visit[edges[top][i].first]==0)
            {
                q.push(edges[top][i].first);
                visit[edges[top][i].first]=1;
                dis1[edges[top][i].first]=dis1[top]+edges[top][i].second;
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //readfile
    //freopen("output.txt","w",stdout);
    ll t,u,v,w;
    scanf("%lld",&t);
    //cin>>t;
    for(ll test=1;test<=t;test++)
    {
        scanf("%lld",&n);
        //cin>>n;
        for(ll i=0;i<n-1;i++)
        {
            dis[i]=0;
            visit[i]=0;
            scanf("%lld %lld %lld",&u,&v,&w);
            //cin>>u>>v>>w;
            edges[u].pb(mp(v,w));
            edges[v].pb(mp(u,w));
        }
        ll ekpranto,oporpranto;
        init();
        ekpranto=BFS(0);
        init();
        oporpranto=BFS(ekpranto);
        BFS1(oporpranto);
        printf("Case %lld:\n",test);
        for(ll i=0;i<n;i++)
        {
            //printf("dis[%lld] = %lld\n",i,dis1[i]);
            edges[i].clear();
            printf("%lld\n",max(dis[i],dis1[i]));
        }
    }
}
