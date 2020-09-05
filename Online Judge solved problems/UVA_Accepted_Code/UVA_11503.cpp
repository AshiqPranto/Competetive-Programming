//DISJOINT SET DATA STRUCTURE PROBLEM....

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

ll parent[mx];
ll rankparent[mx];
map<ll,ll>network;

void makeset()
{
    for(ll i=0;i<mx;i++) parent[i]=i,rankparent[i]=0;
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
    if(px==py) return;
    else if(rankparent[px]<rankparent[py])
    {
        parent[px]=parent[py];
        network[py]+=network[px];
    }
    else if(rankparent[py]<rankparent[px])
    {
        parent[py]=parent[px];
        network[px]+=network[py];
    }
    else
    {
        parent[py]=px;
        network[px]+=network[py];
        network[py]=0;
        rankparent[px]++;
    }
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test,n;
    string a,b;
    cin>>test;
    while(test--)
    {
        map<string,ll>mapping;
        ll i=0;
        cin>>n;
        makeset();
        while(n--)
        {
            cin>>a>>b;
            if(mapping[a]==0) mapping[a]=++i;
            if(mapping[b]==0) mapping[b]=++i;
            if(findParent(mapping[a])!=findParent(mapping[b]))
            {
                unionSet(mapping[a],mapping[b]);
                network[findParent(mapping[a])]++;
            }
            cout<<network[findParent(mapping[a])]+1<<endl;
        }
        network.clear();
    }

}
