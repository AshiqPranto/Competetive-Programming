/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
/*You generate all possible combinations for the left half
and right half, and then sort one side, and for each element
on the other side, search its corresponding one in the sorted
side using binary search.

However, you have 3 choices for each item, i.e. take 0, 1, or
2 of it. So, if we try to calculate exactly, generating all
possible combination for each side should take 3^(n/2) operations
 which is 3^9 in the worst case. let m = 3^(n/2), then the rest of
  the thing can be done in O(m lg m)
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
#define sf(a)   scanf("%d",&a)
#define sfl(a)  scanf("%lld",&a)
#define sff(a,b)    scanf("%d %d",&a,&b)
#define sffl(a,b)   scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define ms(a,b) memset(a, b, sizeof(a))
#define ff  first
#define ss  second
#define lcm(a, b)   ((a)*((b)/__gcd(a,b)))
#define all(a)  a.begin(),a.end()
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

ll n,ans;
vll left_set,right_set,coins(20);

void gen_left_set(ll i,ll value)
{
    left_set.pb(value);
    if(i==n/2) return ;
    gen_left_set(i+1,value);
    gen_left_set(i+1,coins[i]+value);
    gen_left_set(i+1,coins[i]+coins[i]+value);
    return ;
}
void gen_right_set(ll i,ll value)
{
    right_set.pb(value);
    if(i==n) return;
    gen_right_set(i+1,value);
    gen_right_set(i+1,coins[i]+value);
    gen_right_set(i+1,coins[i]+coins[i]+value);
    return ;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //readfile
    ll test,k,x;
    //scanf("%lld",&test);
    sfl(test);
    for(ll t=1;t<=test;t++)
    {
        //coins.clear();
        sffl(n,k);
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            sfl(coins[i]);
            sum+=coins[i]*2;
            //cout<<" x = "<<x<<endl;
            //coins.pb(x);
        }
        ans=0;
        left_set.clear();
        right_set.clear();
        printf("Case %lld: ",t);
        gen_left_set(0,0);
        gen_right_set(n/2,0);
        sort(all(right_set));
        ll sz = left_set.size();
        for(ll i=0;i<sz;i++)
        {
            if(binary_search(all(right_set),k-left_set[i]))
            {
                printf("Yes\n");
                ans = 1;
                break;
            }
        }
        if(ans==0) printf("No\n");

    }
    return 0;
}


