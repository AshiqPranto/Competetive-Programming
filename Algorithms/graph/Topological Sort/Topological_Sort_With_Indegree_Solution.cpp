/* � Ashiq Uddin Pranto
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

#include<bits/stdc++.h>

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
#define mx 109
#define inf 1000000

using namespace std;

ll vertex,edge;
vll edges[mx];
vll top_order;
vll in_degree(mx,0);


void topologicalSort()
{
    for(ll u=0;u<vertex;u++)
    {
        for(ll v=0;v<edges[u].size();v++)
        {
            in_degree[edges[u][v]]++;
        }
    }

    queue<ll>q;
    for(ll i=0;i<vertex;i++)
    {
        if(in_degree[i]==0)
        {
            q.push(i);
        }
    }

    ll cnt=0;

    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        top_order.pb(u);
        for(ll v=0;v<edges[u].size();v++)
        {
            if(--in_degree[edges[u][v]]==0)
            {
                q.push(edges[u][v]);
            }
        }
        cnt++;
    }
    //check if there was a cycle
    if(cnt!=vertex)
    {
        cout<<"There exists a cycle in the graph\n";
        return ;
    }

    for(ll i=0;i<top_order.size();i++) cout<<top_order[i]<<" ";
    cout<<endl;
}

int main()
{
    //readfile
    vertex=6;
    edges[5].pb(2);
    edges[5].pb(0);
    edges[4].pb(0);
    edges[4].pb(1);
    edges[2].pb(3);
    edges[3].pb(1);
    topologicalSort();

}
