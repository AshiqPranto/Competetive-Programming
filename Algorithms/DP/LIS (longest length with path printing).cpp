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
#define EMPTY_VALUE -1

using namespace std;

ll fx[4]={-1,+1,0,0},fy[4]={0,0,+1,-1};
ll length=0,mem[mx],next_index[mx],n;

ll f(ll i,vll &arr)
{
    if(mem[i]!=EMPTY_VALUE) return mem[i];

    ll ans=0;
    ll arrSize = arr.size();
    for(ll j=i+1;j<arrSize;j++)
    {
        if(arr[j]>arr[i])
        {
            ll subResult = f(j,arr);
            if(subResult>ans)
            {
                ans=subResult;
                next_index[i]=j;
            }
        }
    }
    mem[i]=ans+1;
    return mem[i];
}

vll findLis(vll arr)
{
    ll arrSize=arr.size();
    length = 0;
    for(ll i=0;i<arrSize;i++)
    {
        mem[i]=EMPTY_VALUE;
        next_index[i]=EMPTY_VALUE;
    }

    ll start_index = -1;

    for(ll i=0;i<arrSize;i++)
    {
        ll result = f(i,arr);
        if(result>length)
        {
            length=result;
            start_index=i;
        }
    }

    vll lis;
    while(start_index!=-1)
    {
        lis.pb(arr[start_index]);
        start_index = next_index[start_index];
    }
    return lis;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    readfile
    //writefile
    cin>>n;
    vll arr(n,0);
    for(ll i=0;i<n;i++) cin>>arr[i];
    vll lis = findLis(arr);
    printf("Length of a longest increasing subsequence = %lld\n",length);
    printf("LIS = ");
    for(ll i=0;i<lis.size();i++) cout<<lis[i]<<gap;
}

/*
    INPUT:
    7
    5 0 9 2 7 3 4
    OUTPUT:
    4
    LIS: 0 2 3 4
*/
