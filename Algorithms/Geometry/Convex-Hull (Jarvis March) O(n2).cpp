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

struct point{
    ll x,y;

    bool operator==(point p)
    {
        if(x==p.x && y==p.y)
            return 1;
        return 0;
    }
    bool operator < (const point &p)const {
        if(p.x==x) return y<p.y;
        else return x<p.x;
    }
};

ll crossProduct(point a,point b,point c)
{
    ll y1 = b.y-a.y;
    ll y2 = c.y-a.y;
    ll x1 = b.x-a.x;
    ll x2 = c.x-a.x;

    return x1*y2 - x2*y1;
}

ll distance(point a,point b,point c)
{
    ll y1 = b.y - a.y;
    ll y2 = c.y - a.y;
    ll x1 = b.x - a.x;
    ll x2 = c.x - a.x;
    ll temp1 = sqr(x1) + sqr(y1);
    ll temp2 = sqr(x2) + sqr(y2);
    if(temp1 == temp2) return 0;
    else if(temp1<temp2) return -1;
    else return 1;
}

void eff()
{
    printf("Enter the number of points:");
    ll n;
    sfl(n);
    vector<point>points(n);

    for(ll i=0;i<n;i++)
    {
        sffl(points[i].x,points[i].y);
    }

    point start = points[0];
    for(ll i=0;i<n;i++)
    {
        if(points[i].x<start.x)
        {
            start = points[i];
        }
    }
    point current = start;
    set<point>result;
    result.insert(start);
    vector<point>collinearPoints;

    while (true)
    {
        point nextTarget = points[0];
        for(ll i=0;i<n;i++)
        {
            if(points[i]==current)
            {
                continue;
            }
            ll val = crossProduct(current,nextTarget,points[i]);
            if(val > 0)
            {
                nextTarget = points[i];
                collinearPoints.clear();
            }
            else if(val == 0)
            {
                if(distance(current,nextTarget,points[i])<0)
                {
                    collinearPoints.push_back(nextTarget);
                    nextTarget = points[i];
                }
                else
                {
                    collinearPoints.push_back(points[i]);
                }
                
            }
        }
        for(point p: collinearPoints)
        {
            result.insert(p);
        }
        if(nextTarget==start)
        {
            break;
        }
        result.insert(nextTarget);
        current = nextTarget;
    }
    printf("Convex Hull point:\n");
    for(point p : result)
    {
        printf("(%lld,%lld)\n",p.x,p.y);
    }
}

int main()
{
    //fastio
    eff();
    return 0;
}