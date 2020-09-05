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
ll arr[mx],lis[mx],n;

ll findLis()
{
    ll i,maximum=0;
    memset(lis,0,sizeof(lis));
    for(ll i=n-1;i>=0;i--)
    {
        ll len=0;
        for(ll j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                len=max(len,lis[j]);
            }
        }
        lis[i]=len+1;
        maximum=max(maximum,lis[i]);
    }
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
Input:
7
5 0 9 2 7 3 4

Output: 4
*/
