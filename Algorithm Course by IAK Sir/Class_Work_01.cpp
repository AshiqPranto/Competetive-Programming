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
    // int arr[] = {5,3,3,7,10,3,7,6};
    int arr[] = {5,10,1,2,8,14};

    int n = 6;
    // int n = arr.size();

    int maximum[n] = {0};
    int pre_calculate[n] = {0};
    int cum_max[n] = {0};

    for(int i = n-1;i>=0;i--)
    {
        for(int j = i+1;j<n;j++)
        {
            
            if(arr[j]>=arr[i])
            {
                pre_calculate[i] = max(pre_calculate[i],(arr[j]-arr[i]));
            }
        }
        if(i!=n-1) cum_max[i] = max(cum_max[i+1],pre_calculate[i]);
    }


    for(int i = n-1;i>=0;i--)
    {
        for(int j = i+1;j<n;j++)
        {
            if(arr[j]>=arr[i])
            {
                int temp = (arr[j]-arr[i]);
                if(j<n-1)
                {
                    maximum[i] = max(maximum[i],temp+cum_max[j+1]);
                }
                else
                    maximum[i] = max(maximum[i],temp);

                
                // for(int k = j+1;k<n;k++)
                // {
                //     maximum[i] = max(maximum[i],temp+maximum[k]);
                // }
            }
        }
    }
    // cout<<cum_max[0]<<endl;
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        ans = max(ans,maximum[i]);
    }


    cout<<ans<<endl;
    
}

 
int main()
{
    // fastio
    ll test = 1;
    // sfl(test);
    for(ll i=0;i<test;i++)
    {
        // printf("Case %lld: ",i+1);
        eff();
    }
//    cout<<check(81);
    return 0;
}