/* © Ashiq Uddin Pranto
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
#define PI (2*acos(0.0))
#define sqr(x) ((x)*(x))
#define readfile freopen("input.txt","r",stdin)
#define mx 100009
#define inf 1000000

using namespace std;

char ans[]="IEHOVA#";

void path(string a[],ll m,ll n,ll start)
{
    ll x=0;
    ll i=m-1,j=start;
    while(a[i][j]!='#')
    {
        if(i>0 && a[i-1][j]==ans[x] )
        {
            if(x==6) cout<<"forth";
            else
            {
                cout<<"forth ";
            }

            i--;
        }
        else if(j>0 && a[i][j-1]==ans[x])
        {
            if(x==6) cout<<"left";
            else
            {
                cout<<"left ";
            }

            j--;
        }
        else if(j<n-1 && a[i][j+1]==ans[x] )
        {
            if(x==6) cout<<"right";
            else
            {
                cout<<"right ";
            }

            j++;
        }
        x++;
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll test,m,n;
    cin>>test;
    string a[10];
    while(test--)
    {
        cin>>m>>n;
        for(ll i=0;i<m;i++)
        {
            cin>>a[i];
        }
        ll start;
        //for(ll i=0;i<m;i++) cout<<a[i]<<endl;
        for(ll i=0;i<n;i++)
        {
            if(a[m-1][i]=='@')
            {
                start=i;
            }
        }
        path(a,m,n,start);
    }
}

