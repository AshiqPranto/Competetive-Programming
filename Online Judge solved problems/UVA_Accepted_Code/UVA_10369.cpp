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
#define mx 505
#define inf 1000000

using namespace std;

struct edgeStructure
{
    ll u,v;
    double w;
};

bool operator<(edgeStructure lhs,edgeStructure rhs)
{
    return lhs.w<rhs.w;
}

vector<edgeStructure>edges;
ll parent[mx],rankParent[mx];

void makeSet(ll n)
{
    for(ll i=0;i<n;i++)
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


double kruskal(ll s,ll n)
{
    makeSet(n);
    sort(edges.begin(),edges.end());
    ll sz=n;
    double ans=0.0;
    ll count=0;
    for(ll i=0;count!=(sz-s);i++)
    {
        ll pu=findParent(edges[i].u);
        ll pv=findParent(edges[i].v);
        if(pu!=pv)
        {
            unionSet(parent[pu],parent[pv]);
            ans=max(ans,edges[i].w);
            count++;
        }
    }
    return ans;
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,s,p,x,y;
    cin>>t;
    while(t--)
    {
        cin>>s>>p;
        vector<pll>coordinate;
        FOR(1,p)
        {
            cin>>x>>y;
            coordinate.pb(mp(x,y));
        }

        ll sz=coordinate.size();
        //ll count=0;
        for(ll i=0;i<sz;i++)
        {
            for(ll j=i+1;j<sz;j++)
            {
                edgeStructure edge;
                edge.u=i;
                edge.v=j;
                edge.w=sqrt(sqr(coordinate[j].first-coordinate[i].first)+sqr(coordinate[j].second-coordinate[i].second));
                edges.pb(edge);
                //cout<<"weight = "<<edges[count].w<<endl;
                //count++;
                //cout<<"i = "<<i<<" j = "<<j<<" w = "<<edge.w<<endl;
            }
        }
        //sz=edges.size();
        //for(ll i=0;i<sz;i++) cout<<"weight "<<edges[i].u<<" "<<edges[i].v<<endl;
        printf("%0.2lf\n",kruskal(s,p));
        edges.clear();
        coordinate.clear();
    }

}
