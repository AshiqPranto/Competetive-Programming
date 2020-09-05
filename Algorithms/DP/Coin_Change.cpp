/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
//given all coins and the number that we need to make by using the given coin,
//we need calculate the number of ways we can get the given number...  :)

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
#define mx 104
#define inf (ll)1e9
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define EMPTY_VALUE -1

using namespace std;

ll totalCoin;
ll coins[100];
ll numberOfSolutions(ll total)
{

    ll dp[totalCoin+1][total+1];
    for(ll i=0;i<=totalCoin;i++) dp[i][0] = 1;
    for(ll i=0;i<total+1;i++) dp[0][i] = 0;
    for(ll i=1;i<=totalCoin;i++)
    {
        for(ll j=1;j<=total;j++)
        {
            if(coins[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }

        }
    }

    return dp[totalCoin][total];
}
/**
* Space efficient DP solution
*/

ll numberOfSolutionsOnSpace(ll total)
{
    ll dp[total+1] = {0};
    dp[0] = 1;
    for(ll i=0;i<totalCoin;i++)
    {
        for(ll j=1;j<=total;j++)
        {
            if(j>=coins[i])
            {
                dp[j]+=dp[j-coins[i]];
            }
        }
    }
    return dp[total];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    readfile
    ll total;

    cin>>totalCoin>>total;
    for(ll i=0;i<totalCoin;i++) cin>>coins[i];
    cout<<"ans = "<<numberOfSolutionsOnSpace(total);
}

/*
    INPUT:
    3 5  //number of coins and the number we need to make
    1 2 3 // coins

    OUTPUT:
    5
*/
