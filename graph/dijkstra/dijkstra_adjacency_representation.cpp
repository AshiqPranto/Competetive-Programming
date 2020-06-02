#include<bits/stdc++.h>
#define mx 1000009
#define pb(x) push_back(x)
#define ll long long
#define vll vector<ll>
#define inf 1e18
#define readfile freopen("input.txt","r",stdin);
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
    for(int i=1;i<=vertex;i++){
        cout<<source<<" --> "<<i<<" = "<<dis[i]<<endl;
    }
}

int main()
{
    //readfile
    cin>>vertex>>edge;
    ll u,v,w;
    while(edge--)
    {
        cin>>u>>v>>w;
        edges[u].pb(v);
        edges[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
    ll source=1;
    dijkstra(source);
    //vll store;
    //store.pb(vertex);
    if(dis[vertex]==inf) cout<<-1<<endl;
    else
    {
        ll i=vertex;
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

    }
    /*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
OUTPUT->1 4 3 5
    */
}
