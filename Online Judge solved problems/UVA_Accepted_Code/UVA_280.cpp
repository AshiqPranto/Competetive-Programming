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
#define FOR(start,end) for(ll i=start;i<=end;i++)
#define readfile freopen("input.txt","r",stdin);
#define writefile freopen("output.txt","w",stdout);
#define mx 109
#define inf 1000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

vll arr[mx];
ll color[mx][mx];
bool visit[mx][mx];

void makeSet(ll n)
{
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=n;j++) visit[i][j]=0;

    //memset(visit,0,sizeof(visit[0][0])*n*n);

}

void bfs(ll source,ll n)
{
    makeSet(n);
    queue<ll>q;
    set<ll>unik;
    q.push(source);
    while(!q.empty())
    {
        ll top=q.front();
        q.pop();
        for(ll i=0;i<arr[top].size();i++)
        {
            if(visit[top][arr[top][i]]==0)
            {
                //cout<<"push = "<<i<<endl;
                unik.insert(arr[top][i]);
                //cout<<"unik = "<<arr[top][i]<<endl;
                visit[top][arr[top][i]]=1;
                q.push(arr[top][i]);
            }
        }
    }
    set<ll>::iterator it;
    it=unik.begin();
    vll store;
    for(ll i=1;i<=n;i++)
    {
        if(i==*it) it++;
        else
            store.pb(i);
    }
    cout<<store.size();
    for(ll i=0;i<store.size();i++) cout<<" "<<store[i];
    cout<<endl;
}


int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,j,investigatenumber,source;
    while(cin>>n && n!=0)
    {
        while(cin>>i && i!=0)
        {
            while(cin>>j && j!=0)
            {
                arr[i].pb(j);
            }
        }
        cin>>investigatenumber;
        while(investigatenumber--)
        {
            cin>>source;
            bfs(source,n);
        }
        for(ll i=0;i<=n;i++)
             arr[i].clear();
        //memset(arr,0,sizeof(arr[0][0])*mx*mx);
    }
}
