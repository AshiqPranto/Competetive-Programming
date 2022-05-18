/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
// #include<bits/stdc++.h>
#include<iostream>
#include<math.h>
 
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

 
void eff()
{
    double gx,gy,dx,dy,x,y,disofg,disofd;
    // sff(gx,gy);
    // sff(dx,dy);
    cin>>gx>>gy>>dx>>dy;
    while(cin>>x>>y)
    {
        disofg = sqrt(sqr((x-gx))+sqr((y-gy)));
        disofd = sqrt(sqr((x-dx))+sqr((y-dy)));
        if((2.0*disofg)<disofd)
        {
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x,y);
            return;
        }
    }
    printf("The gopher cannot escape.\n");
}
 
int main()
{
    ll test = 1;
    for(ll i=0;i<test;i++)
    {
        eff();
    }
    return 0;
}