//ACCEPTED

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
#include<bits/stdc++.h>

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
#define mx 10009
#define inf 1000000

using namespace std;

struct edgeStructure
{
    ll u,v;
    ll w;
};

bool operator<(edgeStructure lhs,edgeStructure rhs)
{
    return lhs.w<rhs.w;
}

vector<edgeStructure>edges;
ll parent[mx],rankParent[mx],a,airport;

void makeSet(ll n)
{
    airport=0;
    for(ll i=0;i<=n;i++)
    {
        parent[i]=i;
        rankParent[i]=0;
    }
}

ll findParent(ll x)
{
    if(parent[x]==x) return x;
    else
    {
        return parent[x]=findParent(parent[x]);
    }
}

void unionSet(ll x,ll y)
{
    ll px=findParent(x);
    ll py=findParent(y);
    if(rankParent[px]<rankParent[py])
    {
        parent[px]=py;
    }
    else if(rankParent[px]>rankParent[py])
    {
        parent[py]=px;
    }
    else
    {
        parent[py]=px;
        rankParent[px]++;
    }
}


ll kruskal(ll n)
{
    makeSet(n);
    sort(edges.begin(),edges.end());
    ll sz=edges.size();
    ll ans=0;
    for(ll i=0;i<sz;i++)
    {

            ll pu=findParent(edges[i].u);
            ll pv=findParent(edges[i].v);
            if(pu!=pv)
            {
                unionSet(parent[pu],parent[pv]);
                if(edges[i].w>=a) airport++;
                else ans+=edges[i].w;
            }
    }
    return ans;
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,s,p,x,y,n,m;
    cin>>t;
    for(ll test=1;test<=t;test++)
    {
        cin>>n>>m>>a;
        vector<pll>coordinate;

        for(ll i=0;i<m;i++)
        {
                edgeStructure edge;
                cin>>edge.u>>edge.v>>edge.w;
                edges.pb(edge);
        }
        ll ans = kruskal(n);
        set<ll>unikparent;
        for(ll it=1;it<=n;it++)
        {
            unikparent.insert(findParent(it));
        }
        //airport++;
        ans+=(airport+unikparent.size())*a;
        printf("Case %lld: %lld %lld\n",test,ans,(airport+unikparent.size()));
        //cout<<"unik parent size = "<<unikparent.size()<<" Airport = "<<airport<<endl;
        edges.clear();

    }

}
