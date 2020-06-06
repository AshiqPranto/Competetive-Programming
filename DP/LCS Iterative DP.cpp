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

ll lcsIterative(string s,string w)
{
    ll row = s.size();
    ll col = w.size();
    for(ll i=0;i<=col;i++) mem[row][i]=0;
    for(ll i=0;i<=row;i++) mem[i][col]=0;
    for(ll i=col-1;i>=0;i--)
    {
        for(ll j=row-1;j>=0;j--)
        {
            if(s[i]==w[j])
            {
                mem[i][j] = mem[i+1][j+1]+1;
            }
            else
            {
                mem[i][j] = max(mem[i+1][j],mem[i][j+1]);
            }
        }
    }
    return mem[0][0];
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
    cout<<lcsIterative(s,w)<<endl;
}

/*
    INPUT:
    hellom
    hmrll
    OUTPUT:
    3

*/
