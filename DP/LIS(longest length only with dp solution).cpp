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
ll arr[mx],dp[mx],n;

ll lis(ll pos)
{
    ll j,mxlen=1;
    if(dp[pos]!=-1) return dp[pos];
    for(ll j=pos+1;j<n;j++)
    {
        if(arr[j]>arr[pos])
        {
            mxlen=max(mxlen,1+lis(j));
        }
    }
    return dp[pos]=mxlen;
}

ll findLis()
{
    ll i,maximum=0;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n;i++) maximum=max(maximum,lis(i));
    return maximum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    readfile
    //writefile
    cin>>n;
    for(ll i=0;i<n;i++) cin>>arr[i];
    printf("Length of a longest increasing subsequence = %lld\n",findLis());

}
/*
input
7
5 0 9 2 7 3 4
Output: 4
*/
