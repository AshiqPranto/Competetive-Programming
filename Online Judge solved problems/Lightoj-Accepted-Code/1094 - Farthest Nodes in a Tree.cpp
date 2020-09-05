
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
ll n,dis[mx],visit[mx];
vector<pll>edges[mx];

ll farthestNode(ll x)
{
    //cout<<"n = "<<n<<endl;
    dis[x]=0;
    memset(dis,0,sizeof dis);
    memset(visit,0,sizeof visit);
    priority_queue<pll>q;
    visit[x]=1;
    //for(ll i=0;i<edges[x].size();i++)
    //{
        //q.emplace(mp((edges[x][i].second+dis[x]),edges[x][i].first));
        //visit[edges[x][i].first]=1;
    //}
    q.emplace(mp(0,x));

    while(!q.empty())
    {
        pll top=q.top();
        q.pop();
        //cout<<"check "<<top.second<<" ";
        if(dis[top.second]<top.first)
        {
            dis[top.second]=top.first;
        }
        for(ll i=0;i<edges[top.second].size();i++)
        {
            if(visit[edges[top.second][i].first]==0 )
            {
                q.emplace(mp((edges[top.second][i].second+dis[top.second]),edges[top.second][i].first));
                visit[edges[top.second][i].first]=1;
            }
        }
    }
    //cout<<endl;
    ll maximum=-1,index;
    for(ll i=0;i<n;i++)
    {

        if(dis[i]>maximum) maximum=dis[i],index=i;
    }
    return index;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //readfile
    ll t,u,v,w;
    scanf("%lld",&t);
    //cin>>t;
    for(ll test=1;test<=t;test++)
    {
        scanf("%lld",&n);
        //cin>>n;
        for(ll i=0;i<n-1;i++)
        {
            scanf("%lld %lld %lld",&u,&v,&w);
            //cin>>u>>v>>w;
            edges[u].pb(mp(v,w));
            edges[v].pb(mp(u,w));
        }
        printf("Case %lld: ",test);
        ll ans=farthestNode(0);
        //cout<<dis[farthestNode(ans)]<<endl;
        printf("%lld\n",dis[farthestNode(ans)]);
        //cout<<"dis of 1 = "<<dis[1]<<endl;
        for(ll i=0;i<n;i++) edges[i].clear();
    }
}
