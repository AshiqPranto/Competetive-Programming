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

struct Point
{
    ll x,y;
};

bool onSegment(Point p,Point q,Point r)
{
    if(q.x<=max(p.x,r.x) && q.x>=min(p.x,r.x) && q.y<=max(p.y,r.y) && q.y>=min(p.y,r.y)) return true;
    else return false;
}

ll orientation(Point p,Point q,Point r)
{
    ll val = (q.y-p.y) * (r.x-q.x) - (q.x-p.x) * (r.y-q.y);
    if(val ==0 ) return 0;
    return (val>0)?1:2;
}

ll doIntersect(Point p1,Point q1,Point p2,Point q2)
{
    ll o1 = orientation(p1,q1,p2);
    ll o2 = orientation(p1,q1,q2);
    ll o3 = orientation(p2,q2,p1);
    ll o4 = orientation(p2,q2,q1);

    if(o1!=o2 && o3!=o4)
        return true;
    if(o1==0 && onSegment(p1,p2,q1)) return 2;
    if(o2==0 && onSegment(p1,q2,q1)) return true;
    if(o3==0 && onSegment(p2,p1,q2)) return true;
    if(o4==0 && onSegment(p2,q1,q2)) return true;

    return false;
}

bool isInside(vector<Point>& polygon,ll n,Point p)
{
    if(n<3) return false;

    Point extreme = {p.x+inf,p.y+inf+1};
    ll cnt = 0,i=0;
    do{
        ll next = (i+1)%n;

        if(ll a = doIntersect(polygon[i],polygon[next],p,extreme))
        {
            if(a==2) return 1;
            if(orientation(polygon[i],p,polygon[next])==0)
            {
                return onSegment(polygon[i],p,polygon[next]);
            }
            cnt++;
        }
        i=next;
    }while (i!=0);

    return cnt&1;
    
}

void eff()
{
    ll n;
    sfl(n);
    vector<Point>polygon(n);
    for(ll i=0;i<n;i++)
    {
        sffl(polygon[i].x,polygon[i].y);
    }
    ll q;
    Point p;
    sfl(q);
    for(ll i=0;i<q;i++)
    {
        sffl(p.x,p.y);
        isInside(polygon,n,p)? printf("Yes\n"):printf("No\n");
    }
}

int main()
{
    //fastio
    ll test ;
    sfl(test);
    for(ll i=0;i<test;i++)
    {
        printf("Case %lld:\n",i+1);
        eff();
        /* code */
    }
    
    return 0;
}