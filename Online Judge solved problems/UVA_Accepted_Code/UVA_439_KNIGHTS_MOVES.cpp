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

ll visited[10][10];
ll level[10][10];
ll fx[]={2,2,-2,-2,-1,-1,1,1};
ll fy[]={-1,1,-1,1,-2,2,-2,2};

void bfs(ll sx,ll sy)
{
    memset(visited,0,sizeof visited);
    memset(level,0,sizeof level);
    queue<pair<ll,ll> > q;
    level[sx][sy]=0;
    q.push(pll(sx,sy));
    while(!q.empty())
    {
        pll top=q.front();
        q.pop();

        for(ll i=0;i<8;i++)
        {
            ll tx=top.first+fx[i];
            ll ty=top.second+fy[i];
            if(tx>0 && tx<=8 && ty>0 && ty<=8 && visited[tx][ty]==0 && (tx!=sx || ty!=sy))
            {
                visited[tx][ty]=1;
                level[tx][ty]=level[top.first][top.second]+1;
                q.push(pll(tx,ty));
            }
        }
    }
}

using namespace std;
int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    while(cin>>s1>>s2)
    {
        ll sx=s1[0]-96;
        ll sy=s1[1]-'0';
        ll dx=s2[0]-96;
        ll dy=s2[1]-'0';
        bfs(sx,sy);
        printf("To get from %s to %s takes %lld knight moves.\n",s1.c_str(),s2.c_str(),level[dx][dy]);
    }

}
