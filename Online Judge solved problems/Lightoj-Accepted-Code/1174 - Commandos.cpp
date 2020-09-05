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
#define writefile freopen("output.txt","w",stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mx 109
#define inf (ll)1e9
#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

ll fx[4]={-1,+1,0,0},fy[4]={0,0,+1,-1};
ll n,r,s,d,dis,visit[mx],disFromSource[mx],disFromDes[mx],checker;
vector<ll>edges[mx];

void BFS(ll x)
{
    memset(visit,0,sizeof visit);
    queue<ll>q;
    q.emplace(x);
    visit[x]=1;
    disFromDes[x]=0;
    disFromSource[x]=0;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll i=0;i<edges[u].size();i++)
        {
            ll v=edges[u][i];
            if(visit[v]==0)
            {
                visit[v]=1;
                q.emplace(v);
                if(checker==0)
                {

                    disFromSource[v]=disFromSource[u]+1;
                }
                else
                {
                    disFromDes[v]=disFromDes[u]+1;
                }
            }
        }
    }
}

void CLR()
{
    for(ll i=0;i<n;i++)
    {
        edges[i].clear();
        disFromSource[i]=0;
        disFromDes[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //readfile
    //writefile
    ll t,u,v,w;
    scanf("%lld",&t);
    //cin>>t;
    for(ll test=1;test<=t;test++)
    {
        scanf("%lld%lld",&n,&r);
        //cin>>n;
        CLR();
        for(ll i=0;i<r;i++)
        {
            scanf("%lld %lld",&u,&v);
            edges[u].pb(v);
            edges[v].pb(u);
        }
        scanf("%lld %lld",&s,&d);
        checker=0;
        BFS(s);
        checker=1;
        BFS(d);
        ll maxi=0;
        for(ll i=0;i<n;i++)
        {
            maxi=max(disFromDes[i]+disFromSource[i],maxi);
        }
        printf("Case %lld: %lld\n",test,maxi);

    }
}
