
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
#define mx 200
#define inf 1000000

using namespace std;

ll parent[mx];
ll rankParent[mx];

void makeset(ll n)
{
    // At first the representative of a node is itself
    //and the rank of all representative is zero initially
    //printf("makeset n = %lld\n",n);
    for(ll i=0;i<mx;i++)
    {
        parent[i]=i;
        //printf("parent [i] = %lld\n",parent[i]);
        rankParent[i]=0;
    }
}

ll findParent(ll x)
{
    //printf("find parent = %lld\n",parent[x]);
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

void unionSet(ll x,ll y)
{
    // we use Path compression and Union by Rank method
    // to compressed the tree....
    ll px=findParent(x);
    ll py = findParent(y);
    //printf("px = %lld px = %lld\n",px,py);
    if(px==py) return;
    if(rankParent[px]<rankParent[py])
    {
        parent[px]=parent[py];
    }
    else if(rankParent[py]<rankParent[px])
    {
        parent[py]=parent[px];
    }
    else
    {
        parent[py]=px;
        rankParent[px]++;
    }
}

void printSet(ll n)
{
    for(ll i=65;i<=n;i++)
    {
        cout<<"Node is "<<i<<" Parent is "<<parent[i]<<" Rank is "<<rankParent[i]<<endl;
    }
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t;
    char s[5],c[5];
    string a,b;
    char highest_node[5];
    scanf("%lld\n",&t);
    //gets(c);
    //printf("%s",c);
    for(ll z=1;z<=t;z++)
    {
        set<ll>unik;
        gets(c);
        makeset(c[0]);
        //printf("%s\n",c);
        while(gets(s))
        {
            if(s[0]=='\0') break;
            unionSet(s[0],s[1]);
            //printf("%s\n",s);
        }
        for(ll i=65;i<=c[0];i++)
        {
            unik.insert(findParent(i));
        }
        cout<<unik.size()<<endl;
        //printSet(c[0]);
        if(z!=t) cout<<endl;
    }

}
