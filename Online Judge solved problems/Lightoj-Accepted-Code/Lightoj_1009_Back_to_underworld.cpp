/*
 *      ┌─┐       ┌─┐ + +
 *   ┌──┘ ┴───────┘ ┴──┐++
 *   │                 │
 *   │       ───       │++ + + +
 *   ███████───███████ │+
 *   │                 │+
 *   │       ─┴─       │
 *   │                 │
 *   └───┐         ┌───┘
 *       │         │
 *       │         │   + +
 *       │         │       Code is far away from bug with the animal protecting
 *       │         └──────────────┐
 *       │                        │
 *       │                        ├─┐
 *       │                        ┌─┘
 *       │                        │
 *       └─┐  ┐  ┌───────┬──┐  ┌──┘  + + + +
 *         │ ─┤ ─┤       │ ─┤ ─┤
 *         └──┴──┘       └──┴──┘  + + + +
 *

 █▒▒▒▒▒▒▒▒▒
10%
███▒▒▒▒▒▒▒
30%
█████▒▒▒▒▒
50%
███████▒▒▒
70%
██████████
100%
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
#define mx 20005
#define inf 1000000

using namespace std;

vector<vll>a(mx);
ll level[mx],visited[mx];

void bfs(ll x)
{
    memset(level,0,sizeof level);
    memset(visited,0,sizeof visited);
    queue<ll>q;
    q.push(x);
    level[x]=1;
    visited[x]=1;
    while(!q.empty())
    {
        ll top=q.front();
        q.pop();
        for(ll i=0;i<a[top].size();i++)
        {
            ll node=a[top][i];
            if(visited[node]==0)
            {
                visited[node]=1;
                level[node]=level[top]+1;
                q.push(node);
            }
        }
    }
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,u,v;
    scanf("%lld",&t);
    for(ll test=1;test<=t;test++)
    {
        scanf("%lld",&n);
        set<ll>unik;
        while(n--)
        {
            scanf("%lld %lld",&u,&v);
            unik.insert(u);
            unik.insert(v);
            a[u].pb(v);
            a[v].pb(u);
        }
        bfs(u);
        set<ll>::iterator it;
        it=unik.begin();
        ll countodd=0,counteven=0;
        for(;it!=unik.end();it++)
        {
            if(level[*it]>0 && level[*it]%2==1) countodd++;
            else if(level[*it]>0 && level[*it]%2==0) counteven++;
        }
        //for(ll i=1;i<=3;i++) cout<<"level = "<<level[i]<<endl;
        printf("Case %lld: %lld\n",test,max(counteven,countodd));
        for(ll i=0;i<mx;i++) a[i].clear();

    }

}
