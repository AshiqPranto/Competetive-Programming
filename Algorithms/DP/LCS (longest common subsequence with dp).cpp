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
#define mx 1000
#define inf (ll)1e9
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define EMPTY_VALUE -1

using namespace std;

ll fx[4]={-1,+1,0,0},fy[4]={0,0,+1,-1};
ll mem[mx][mx];

ll lcs(ll i,ll j,string &s,string &w)
{
    if(i==s.size() || j==w.size()) return 0;

    if(mem[i][j]!=EMPTY_VALUE)
    {
        return mem[i][j];
    }
    ll ans=0;
    if(s[i]==w[j])
    {
        ans = 1+lcs(i+1,j+1,s,w);
    }
    else
    {
        ll val1 = lcs(i+1,j,s,w);
        ll val2 = lcs(i,j+1,s,w);

        ans = max(val1,val2);
    }
    mem[i][j]=ans;
    return mem[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    readfile
    //writefile
    string s,w;
    memset(mem,-1,sizeof(mem[0][0])*mx*mx);
    cin>>s>>w;
    cout<<lcs(0,0,s,w);
}

/*
    INPUT:
    hellom
    hmrll
    OUTPUT:
    3

*/
