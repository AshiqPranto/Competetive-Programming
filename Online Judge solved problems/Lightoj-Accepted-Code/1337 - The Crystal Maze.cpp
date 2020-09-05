/* � Ashiq Uddin Pranto
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
#define gap " "
#define mx 509
#define inf (ll)1e9
#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

ll fx[4]={-1,+1,0,0},fy[4]={0,0,+1,-1};
ll visit[mx][mx],direction[mx][mx],m,n,matrix[mx][mx];
char cell[mx][mx];

ll bfs(ll x,ll y)
{
     memset(visit,0,sizeof(visit[0][0])*(mx)*(mx));

    queue<pll>q;
    q.emplace(mp(x,y));
    visit[x][y]=1;
    ll ans=0;
    while(!q.empty())
    {
        pll top = q.front();
        q.pop();
        //cout<<top.first<<gap<<top.second<<endl;
        //cout<<ans<<endl;
        if(cell[top.first][top.second]=='C') ans++;
        for(ll i=0;i<4;i++)
        {
            x=top.first+fx[i];
            y=top.second+fy[i];
            if(x>=0 && x<m && y>=0 && y<n && (cell[x][y]=='.' || cell[x][y]=='C') && visit[x][y]==0)
            {
                q.emplace(mp(x,y));
                visit[x][y]=1;
                //cout<<"check";
            }
        }
    }
    return ans;
}
void bfs1(ll x,ll y,ll value)
{
     memset(visit,0,sizeof(visit[0][0])*(mx)*(mx));
     queue<pll>q;
    q.emplace(mp(x,y));
    visit[x][y]=1;

    while(!q.empty())
    {
        //cout<<"check\n";
        pll top = q.front();
        q.pop();
        matrix[top.first][top.second]=value;

        for(ll i=0;i<4;i++)
        {
            x=top.first+fx[i];
            y=top.second+fy[i];
            if(x>=0 && x<m && y>=0 && y<n && (cell[x][y]=='.' || cell[x][y]=='C') && visit[x][y]==0)
            {
                q.emplace(mp(x,y));
                visit[x][y]=1;
                //cout<<"check";
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //readfile
    //writefile
    ll t,q,x,y;
    scanf("%lld",&t);

    for(ll test=1;test<=t;test++)
    {
        scanf("%lld %lld %lld",&m,&n,&q);
        for(ll i=0;i<m;i++)
        {
                scanf("%s",cell[i]);
        }
        for(ll i=0;i<=m;i++)
        {
            for(ll j=0;j<=n;j++)
            {
                matrix[i][j]=-1;
            }
        }
        printf("Case %lld:\n",test);

        /*for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(matrix[i][j]==-1 && cell[i][j]!='#')
                {
                    //cout<<"i = "<<i<<" j = "<<j<<endl;
                    ll x=bfs(i,j);
                    bfs1(i,j,x);
                }
            }
        }*/
        /*for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                //printf("matrix[%lld][%lld] = %lld\n",i,j,matrix[i][j]);
            }
        }*/

        for(ll i=0;i<q;i++)
        {
            scanf("%lld %lld",&x,&y);
            x--;
            y--;
            if(matrix[x][y]!=-1) printf("%lld\n",matrix[x][y]);
            else
            {
                ll ans=bfs(x,y);
                printf("%lld\n",ans);
                bfs1(x,y,ans);
            }
        }
    }
}
