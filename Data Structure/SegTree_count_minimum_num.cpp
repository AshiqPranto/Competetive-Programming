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

struct item
{
    ll m,c;
};

struct segtree
{
    ll size;
    vector<item> values;

    void init(ll n)
    {
        size = 1;
        while (size<n) size*=2;
        // size*=2;
        // values.assign(2*size,0LL);
        values.resize(2*size);
    }

    item merge(item m1,item m2)
    {
        if(m1.m<m2.m) return m1;
        if(m2.m<m1.m) return m2;
        else
        {
            return {m1.m,m1.c+m2.c};
        }
        
    }

    void build(vll &a,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
            if(lx<(ll)a.size())
            {
                values[x] = {a[lx],1};
            }
            return;
        }
        ll m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        values[x] = merge(values[2*x+1],values[2*x+2]);
    }
    void build(vll &a)
    {
        build(a,0,0,size);
    }

    void set(ll i,ll v,ll x,ll lx,ll rx)
    {
        if(rx-lx==1) {
            values[x] = {v,1};
            return ;
        }
        ll m = (lx+rx)/2;
        if(i<m)
        {
            set(i,v,2*x+1,lx,m);
        }
        else 
        {
            set(i,v,2*x+2,m,rx);
        }
        values[x] = merge(values[2*x+1],values[2*x+2]);
    }

    void set(ll i,ll v)
    {
        set(i,v,0,0,size);
    }

    item minimum(ll l,ll r,ll x,ll lx,ll rx)
    {
        if(lx>=r || l>=rx) return {(ll)1e17,(ll)0};
        if(lx>=l && rx<=r) return values[x];
        ll m = (lx+rx)/2;
        item s1 = minimum(l,r,x*2+1,lx,m);
        item s2 = minimum(l,r,x*2+2,m,rx);
        return merge(s1,s2);
    }

    item minimum(ll l,ll r)
    {
        return minimum(l,r,0,0,size);
    }

};



int main()
{
    //fastio
    ll n,m;
    sffl(n,m);
    segtree st;
    st.init(n);
    vll a(n);
    for(ll i=0;i<n;i++) sfl(a[i]);
    st.build(a);
    debug(st.minimums);
    while(m--)
    {
        ll op;
        sfl(op);
        if(op==1)
        {
            ll i,v;
            sffl(i,v);
            st.set(i,v);
        }
        else
        {
            ll l,r;
            sffl(l,r);
            item ans = st.minimum(l,r);
            printf("%lld %lld\n",ans.m,ans.c);
        }
        
    }
    return 0;
}
// INPUT:
// 5 5
// 5 4 2 3 5
// 2 0 3
// 1 1 1
// 2 0 3
// 1 3 1
// 2 0 5

// OUTPUT:
// 11
// 8
// 14

