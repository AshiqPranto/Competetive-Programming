//AC IN ONE GO......

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
//#define mx 100
#define inf 1000000

using namespace std;

char grid[25][25];
ll visited[25][25];
ll fx[]={-1,1,0,0};
ll fy[]={0,0,-1,1};
ll w,h;
ll bfs(ll x,ll y)
{
    memset(visited,0,sizeof(visited[0][0])*25*25);
    //cout<<"x="<<x<<" y = "<<y<<endl;
    ll count=0;
    queue<pll>q;
    q.push(pll(x,y));
    visited[x][y]=1;
    while(!q.empty())
    {
        //cout<<"queue"<<endl;
        pll node=q.front();
        //cout<<"first = "<<node.first<<" second = "<<node.second<<endl;
        q.pop();
        for(ll i=0;i<4;i++)
        {
            ll tx=node.first+fx[i];
            ll ty=node.second+fy[i];
            if(tx>=0 && tx<h && ty>=0 && ty<w && grid[tx][ty]=='.' && visited[tx][ty]==0)
            {
                visited[tx][ty]=1;
                q.push(pll(tx,ty));
                count++;
            }
        }
    }
    memset(grid,0,sizeof grid);
    return count+1;
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    scanf("%lld",&t);
    //for(ll i=0;i<t;i++)
    for(ll test=1;test<=t;test++)
    {
        scanf("%lld %lld",&w,&h);
        //printf("%lld %lld\n",w,h);
        for(ll i=0;i<h;i++)
        {
            scanf("%s",grid[i]);
        }
        ll x,y;
        for(ll i=0;i<h;i++)
        {
            for(ll j=0;j<w;j++)
            {
                if(grid[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
            }

        }

        printf("Case %lld: %lld\n",test,bfs(x,y));

    }
}
