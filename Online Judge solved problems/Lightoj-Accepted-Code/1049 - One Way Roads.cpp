/* © Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
//AC IN ONE GO....:)
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
ll n,r,s,d,dis,visit[mx],checker,direction[mx][mx];
vector<ll>edges[mx];
vector<ll>cost[mx];

ll BFS(ll x)
{
    ll ans=0,counter=0;
    memset(visit,0,sizeof visit);
    queue<ll>q;
    visit[x]=1;
    //cout<<edges[x][0];
    if(checker==0)
    {
        q.push(edges[x][0]);
        if(direction[x][edges[x][0]]==0) ans+=cost[x][0];
        visit[edges[x][0]]=1;
    }
    else
    {
        q.push(edges[x][1]);
        if(direction[x][edges[x][1]]==0) ans+=cost[x][1];
        visit[edges[x][1]]=1;
    }

        while(!q.empty())
        {
            ll u=q.front();
            q.pop();
            for(ll i=0;i<edges[u].size();i++)
            {
                ll v=edges[u][i];
                if(visit[v]==0)
                {
                    q.push(v);
                    visit[v]=1;
                    if(direction[u][v]==0)
                    {
                        ans+=cost[u][i];
                        //cout<<"ans = "<<cost[u][i]<<endl;
                    }
                }
            }
            if(counter==0)
            {
                visit[x]=0;
                counter=1;
            }
        }
    return ans;
}

void CLR()
{
    for(ll i=0;i<=n;i++)
    {
        edges[i].clear();
        cost[i].clear();
    }
    memset(direction,0,sizeof(direction[0][0])*mx*mx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //readfile
    //writefile
    ll t,u,v,w;
    scanf("%lld",&t);
    for(ll test=1;test<=t;test++)
    {
        scanf("%lld",&n);
        //cin>>n;
        CLR();
        for(ll i=0;i<n;i++)
        {
            scanf("%lld %lld %lld",&u,&v,&w);
            edges[u].pb(v);
            edges[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
            direction[u][v]=1;
        }
        checker=0;
        //cout<<"check"<<endl;
        ll ans1=BFS(1);
        //cout<<"check"<<endl;
        checker=1;
        ll ans2=BFS(1);

        printf("Case %lld: %lld\n",test,min(ans1,ans2));

    }
}
