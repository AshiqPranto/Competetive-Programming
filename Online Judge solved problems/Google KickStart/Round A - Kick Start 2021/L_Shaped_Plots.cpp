/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
#include<bits/stdc++.h>
 
#define ll long long
#define ld long double
#define FOR(x,y) for(ll i=x;i<=y;i++)
#define f0(x) for(ll i = 0;i<=x;i++)
#define f1(x) for(ll i = 1;i<=x;i++)
#define pb(x) push_back(x)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define matrix(x) vector<vector<x>>
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
#define inf (ll)1e17
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define EMPTY_VALUE -1
#define mod 1000000007
#define MOD(a,b) (a%b + b)%b
 
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void eff()
{
    ll r,c;
    sffl(r,c);
    // ll arr[r][c] = {0},left[r][c] = {0},right[r][c] = {0},up[r][c] = {0},down[r][c] = {0};
    vector<vector<ll>>arr(r,vector<ll>(c,0));
    vector<vector<ll>>left(r,vector<ll>(c,0));
    vector<vector<ll>>right(r,vector<ll>(c,0));
    vector<vector<ll>>up(r,vector<ll>(c,0));
    vector<vector<ll>>down(r,vector<ll>(c,0));

    f0((r-1))
    {
        for(ll j = 0;j<c;j++)
        {
            sfl(arr[i][j]);
        }
    }
    f0((r-1))
    {
        for(ll j = 0;j<c;j++)
        {
            // cout<<"["<<i<<"]["<<j<<"]"<<endl;
            
            if(arr[i][j]==1)
            {
                left[i][j] = 1;
                if(j>0) left[i][j] = left[i][j-1]+1;
                // if(j<c-1) right[i][j] = right[i][j+1]+1; //,cout<<"["<<i<<"]["<<j<<"] = "<<right[i][j]<<endl;
                // if(i>0) up[i][j] = up[i-1][j]+1;
                // if(i<r-1) down[i][j] = down[i+1][j]+1;
            }
        }
    }
    f0((r-1))
    {
        for(ll j = c-1;j>=0;j--)
        {
            // cout<<"["<<i<<"]["<<j<<"]"<<endl;
            
            if(arr[i][j]==1)
            {
                right[i][j] = 1;
                if(j<c-1) right[i][j] = right[i][j+1]+1;
            }
        }
    }
    for(ll j = 0;j<c;j++)
    {
        for(ll i = 0;i<r;i++)
        {
            if(arr[i][j]==1)
            {
                up[i][j] = 1;
                if(i>0) up[i][j] = up[i-1][j]+1;
            }
        }
    }
    for(ll j = 0;j<c;j++)
    {
        for(ll i = r-1;i>=0;i--)
        {
            if(arr[i][j]==1)
            {
                down[i][j] = 1;
                if(i<r-1) down[i][j] = down[i+1][j]+1;
            }
        }
    }

    // debug(left);
    // debug(right);
    // debug(up);
    // debug(down);

    ll cnt = 0;
    f0((r-1))
    {
        for(ll j = 0;j<c;j++)
        {
            if(arr[i][j]==1)
            {
                if(up[i][j]>1)
                {
                    if(left[i][j]>2) cnt+=min(up[i][j],left[i][j]/2)-1;
                    if(right[i][j]>2) cnt+=min(up[i][j],right[i][j]/2)-1;
                }
                if(down[i][j]>1)
                {
                    if(left[i][j]>2) cnt+=min(down[i][j],left[i][j]/2)-1;
                    if(right[i][j]>2) cnt+=min(down[i][j],right[i][j]/2)-1;
                }
                if(left[i][j]>1)
                {
                    if(up[i][j]>2) cnt+=min(left[i][j],up[i][j]/2)-1;
                    if(down[i][j]>2) cnt+=min(left[i][j],down[i][j]/2)-1;
                }
                if(right[i][j]>1)
                {
                    if(up[i][j]>2) cnt+=min(right[i][j],up[i][j]/2)-1;
                    if(down[i][j]>2) cnt+=min(right[i][j],down[i][j]/2)-1;
                }
            }
        }
    }
    cout<<cnt<<endl;

    
}
 
int main()
{
    // fastio
    ll test = 1;
    sfl(test);
    for(ll i=0;i<test;i++)
    {
        printf("Case #%lld: ",i+1);
        eff();
    }
//    cout<<check(81);
    return 0;
}