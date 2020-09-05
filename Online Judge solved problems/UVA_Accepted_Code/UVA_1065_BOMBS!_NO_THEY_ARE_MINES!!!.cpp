//AC IN ONE GO....

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

ll cell[1005][1005];
ll fx[]={1,-1,0,0};
ll fy[]={0,0,1,-1};
ll level[1005][1005],vis[1005][1005];
ll row,col;

void bfs(ll sx,ll sy)
{
    memset(vis,0,sizeof vis);
    memset(level,0,sizeof level);
    vis[sx][sy]=1;
    queue<pll>q;
    queue<pair<ll,ll> > q1;

    q.push(pll(sx,sy));
    while(!q.empty())
    {
        pll top=q.front();
        q.pop();
        for(ll k=0;k<4;k++)
        {
            ll tx=top.first+fx[k];
            ll ty=top.second+fy[k];
            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                level[tx][ty]=level[top.first][top.second]+1;
                q.push(pll(tx,ty));
            }
        }
    }
}

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>row>>col)
    {
        if(row==0 && col==0) break;
        ll n,r,numofr,c;
        cin>>n;
        while(n--)
        {
            cin>>r>>numofr;
            while(numofr--)
            {
                cin>>c;
                cell[r][c]=-1;
            }
        }
        ll sourcex,sourcey,dx,dy;
        cin>>sourcex>>sourcey>>dx>>dy;
        bfs(sourcex,sourcey);
        cout<<level[dx][dy]<<endl;
        memset(cell,0,sizeof cell);
    }
}
