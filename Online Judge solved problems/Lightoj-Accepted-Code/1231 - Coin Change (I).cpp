/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
//Accepted
// This is my first limited coin change problem... :)
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

#define ll long long int
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
#define ss1(x) scanf("%lld",&x)
#define ss2(x,n) scanf("%lld %lld",&x,&n)
#define readfile freopen("input.txt","r",stdin);
#define writefile freopen("output.txt","w",stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define gap " "
#define mx 104
#define inf (ll)1e9
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define EMPTY_VALUE -1
#define mod 100000007

using namespace std;

ll n;
vll coins(51),repeat(51);
ll dp[51][1001];
ll limitedSubsetSum(ll i,ll amount)
{
    if(amount==0) return 1;
    if(i>=n || amount<0)    return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];
    ll res=0;
    for(ll j=1;j<=repeat[i];j++)
    {
        res+=limitedSubsetSum(i+1,amount-(j*coins[i]))%mod;
    }
    res+=limitedSubsetSum(i+1,amount)%mod;
    return dp[i][amount] = res%mod;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //0readfile
    ll test,k,x;
    //scanf("%lld",&test);
    ss1(test);
    for(ll t=1;t<=test;t++)
    {
        //coins.clear();
        ss2(n,k);
        for(ll i=0;i<n;i++)
        {
            ss1(coins[i]);
            //cout<<" x = "<<x<<endl;
            //coins.pb(x);
        }

        for(ll i=0;i<n;i++)
        {
            ss1(repeat[i]);
        }
        memset(dp,-1,sizeof(dp[0][0])*51*1001);
        //cout<<"coins = ";
        //for(ll i=0;i<n;i++) cout<<coins[i]<<" ";
        //printf("input completed\n");
        printf("Case %lld: %lld\n",t,limitedSubsetSum(0,k));
    }
    return 0;
}



/*
    INPUT:
    3 5  //number of coins and the number we need to make
    1 2 3 // coins

    OUTPUT:
    5
*/
