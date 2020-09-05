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
#define mx 1009
#define inf 1e18
#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

vll edges[mx],cost[mx];
ll vertex,edge;
ll dis[mx];
ll parents[mx];
struct node
{
    ll u;
    ll cost;
    node(ll _u,ll _cost)
    {
        u=_u;
        cost=_cost;
    }
    bool operator < ( const node& p ) const {      return cost > p.cost;   } //Operator overloading
};

void dijkstra(ll source)
{
    for(ll i=1;i<=vertex;i++) dis[i]=inf,parents[i]=-1;
    //parents[source]=source;
    priority_queue<node>q;
    q.push(node(source,0));
    dis[source]=0;

    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        ll u=top.u;

        for(ll i=0;i<edges[u].size();i++)
        {
            ll v=edges[u][i];

            if(dis[u]+cost[u][i]<dis[v])
            {
                dis[v]=dis[u]+cost[u][i];
                q.push(node(v,dis[v]));
                parents[v]=u;
            }
        }
    }
    /*for(int i=1;i<=vertex;i++){
        cout<<source<<" --> "<<i<<" = "<<dis[i]<<endl;
    }*/
}

int main()
{
    //readfile
    ll test;
    scanf("%lld",&test);
    for(ll t=1;t<=test;t++)
    {
        scanf("%lld %lld",&vertex,&edge);
        //cin>>vertex>>edge;
        ll u,v,w;
        while(edge--)
        {
            scanf("%lld %lld %lld",&u,&v,&w);
            //cin>>u>>v>>w;
            edges[u].pb(v);
            edges[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        ll source=1;
        dijkstra(source);
        //vll store;
        //store.pb(vertex);
        printf("Case %lld: ",t);
        if(dis[vertex]==inf) printf("Impossible\n");
        else
        {
            printf("%lld\n",dis[vertex]);
            /*ll i=vertex;
            vll store;
            store.pb(vertex);
            while(parents[i]!=-1)
            {
                store.pb(parents[i]);
                i=parents[i];

            }
            cout<<endl;
            cout<<"expected path...\n";
            for( i=store.size()-1;i>=0;i--) cout<<store[i]<<" ";
            */
        }
        for(ll i=0;i<=vertex;i++)
        {
            edges[i].clear();
            cost[i].clear();
        }
    }

}
