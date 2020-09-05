//AC AFTER WASTING SOME TIMES FOR DEBUGGING......
//Always try to implements your own ideas...

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
char grid[12][12];
ll rowfirst,colfirst,rowlast,collast;
ll level[12][12];
bool visited[12][12];
ll fx[]={-1,1,0,0};
ll fy[]={0,0,-1,1};
void bfs(ll n,char maxchar)
{
    memset(level,0,sizeof(level[0][0])*12*12);
    memset(visited,0,sizeof(visited[0][0])*12*12);
    queue<pll>q;
    q.push(pll(rowfirst,colfirst));
    grid[rowfirst][colfirst]='.';
    visited[rowfirst][colfirst]=1;
    ll word=66;
    while(!q.empty())
    {
        pll node=q.front();
        q.pop();
        for(ll k=0;k<4;k++)
        {
            ll tx=node.first+fx[k];
            ll ty=node.second+fy[k];
            if(tx>=0 && tx<n && ty>=0 && ty<n && visited[tx][ty]==0 && (grid[tx][ty]=='.' || grid[tx][ty]==word))
            {
                visited[tx][ty]=1;

                level[tx][ty]=level[node.first][node.second]+1;
                q.push(pll(tx,ty));
                if(grid[tx][ty]==maxchar)
                {
                    return ;
                }
                if(grid[tx][ty]==word )
                {
                    grid[tx][ty]='.';
                    memset(visited,0,sizeof(visited[0][0])*12*12);
                    visited[tx][ty]=1;
                    word++;
                    while(!q.empty()) q.pop();
                    q.push(pll(tx,ty));
                    break;
                }

            }
        }
    }
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n;
    scanf("%lld",&t);
    for(ll test=1;test<=t;test++)
    {
        scanf("%lld",&n);
        for(ll i=0;i<n;i++)
        {
            scanf("%s",grid[i]);
        }
        char maxchar='A';
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(grid[i][j]>=65 && grid[i][j]<=90)
                {
                    if(maxchar<=grid[i][j])
                    {
                        maxchar=grid[i][j];
                        rowlast=i;
                        collast=j;
                    }
                    if(grid[i][j]==65)
                    {

                        rowfirst=i;
                        colfirst=j;
                    }
                }
            }
        }
        bfs(n,maxchar);
        if(maxchar=='A') printf("Case %lld: 0\n",test);
        else if(level[rowlast][collast]==0)
        {
            printf("Case %lld: Impossible\n",test);
        }
        else
        {
            printf("Case %lld: %lld\n",test,level[rowlast][collast]);
        }
    }

}
