/* Ashiq Uddin Pranto
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
#define readfile freopen("input.txt","r",stdin)
#define mx 10009
#define inf 1000000

using namespace std;
vll edges[mx];
vll dis(mx,inf);
vll visited(mx,0);
//ll distance[mx];
set<ll>unik;

void bfs(ll source)
{
    queue<ll>Q;
    visited[source]=1;
    //dis[source]=0;
    Q.push(source);
    unik.insert(source);
    while(!Q.empty())
    {
        ll node=Q.front();
        //cout<<"node = "<<node<<endl;
        Q.pop();

        for(ll i=0;i<edges[node].size();i++)
        {
            ll nextnode = edges[node][i];
            if(visited[nextnode]==0)
            {
                //cout<<"next node = "<<nextnode<<endl;
                visited[nextnode]=1;
                //dis[nextnode]=dis[node]+1;
                Q.push(nextnode);
                unik.insert(nextnode);
            }
        }
    }

}

int main()
{
    //readfile;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll numofedge,numofnode;
    ll test1,l;
    cin>>test1;
    for(ll t=0;t<test1;t++)
    {
        cin>>numofnode>>numofedge>>l;
        ll x,y;

        for(ll i=1;i<=numofedge;i++)
        {
            cin>>x>>y;
            edges[x].pb(y);
            //edges[y].pb(x);
        }
        ll source;

        for(ll i=0;i<l;i++)
        {
            cin>>source;
            bfs(source);
        }
        cout<<unik.size()<<endl;
        unik.clear();
        for(ll i=0;i<mx;i++)
        {
            edges[i].clear();
            visited[i]=0;
        }
    }
}
