/* Ashiq Uddin Pranto
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
#define mx 100006
#define inf 1000000

using namespace std;

struct edgeStructure
{
    ll u,v,w;
};

bool operator<(edgeStructure lhs,edgeStructure rhs)
{
    return lhs.w<rhs.w;
}

vector<edgeStructure>edgeVector;
vector<edgeStructure>edgesOfMst;
ll parent[mx];
ll rankParent[mx];
ll parents[mx],room[55][55];

void makeSet(ll n)
{
    for(ll i=0;i<=n;i++)
    {
        parent[i]=i;
        rankParent[i]=0;
        parents[i]=-1;
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
    sort(edgeVector.begin(),edgeVector.end());

    ll sz=edgeVector.size();

    ll ans=0,edge=0;
    for(ll i=0;i<sz;i++)
    {
        ll pu=findParent(edgeVector[i].u);
        ll pv=findParent(edgeVector[i].v);
        if(pu!=pv)
        {
            edge++;
            unionSet(parent[pu],parent[pv]);
            room[edgeVector[i].u][edgeVector[i].v]=0;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            ans+=room[i][j];
        }
    }
    if(edge!=n-1) return -1;
    else
    return ans;
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll vertex,edge,test;
    cin>>test;
    for(ll t=1;t<=test;t++)
    {
        cin>>vertex;
        //makeSet(vertex);
        for(ll i=1;i<=vertex;i++)
        {
            for(ll j=1;j<=vertex;j++)
            {
                cin>>room[i][j];
                if(i!=j && room[i][j]!=0)
                {
                    edgeStructure e;
                    e.u=i,e.v=j,e.w=room[i][j];
                    edgeVector.pb(e);
                }

            }
        }
        printf("Case %lld: %lld\n",t,kruskal(vertex));
        edgeVector.clear();
    }
}
