/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
#include<bits/stdc++.h>

#define ll long long
#define ld long double
#define FOR(x,y) for(ll i=x;i<=y;i++)
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
#define inf (ll)1e9
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
    ll x1,y1,r1,x2,y2,r2;
    sfffl(x1,y1,r1);
    sfffl(x2,y2,r2);
    double d = (double)sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    if(d>=r1+r2)
    {
        printf("%0.10lf\n",0);
        return;
    }
    else if((d+min(r1,r2))<=r1 || (d+min(r1,r2))<=r2)
    {
        printf("%0.10lf\n",PI*sqr(min(r1,r2)));
        return;
    }
    // else if(d<r1 || d<r2)
    // {
    //     printf("%0.10lf\n",PI*sqr(min(r1,r2)));
    //     return;
    // }
    double theta = (double)acos((sqr(r1)+sqr(d)-sqr(r2))/(2.0000000*r1*d))*180/PI;
    theta*=2.000000;
    debug(d,theta);
    double ans = (double)0.000000;
    ans+=((PI*sqr(r1)*theta)/360.00000) - (0.500000*sqr(r1)*sin(theta*PI/180.00000));
    debug(ans);
    theta = acos((sqr(r2)+sqr(d)-sqr(r1))/(2.0*r2*d))*180/PI;
    theta*=2.000000;
    debug((sqr(r2)+sqr(d)-sqr(r1)));
    debug((2.0*r2*d));
    debug(theta);
    ans+=(PI*sqr(r2)*theta/360.000000)-(0.5*sqr(r2)*sin(theta*PI/180.00000));
    printf("%0.10lf\n",max(ans,(double)0.000000));
}

int main()
{
    //fastio
    // printf("%0.8lf",(double)sin(82.819));
    ll test ;
    sfl(test);
    for(ll i=1;i<=test;i++)
    {
        printf("Case %lld: ",i);
        eff();
    }
    return 0;
}