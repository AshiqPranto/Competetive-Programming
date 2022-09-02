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

int prevalue[1005][1005];
vector<pair<int,int>>monsters;
bool vis[1005][1005];
int n,m;
string s[1005];
string ans;
map<pair<int,int>,pair<int,int>>parent;

int x[4] = {1,-1,0,0};
int y[4] = {0,0,1,-1};

bool isValid(int nx,int ny)
{
    if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==false && s[nx][ny]!='#')
    {
        return true;
    }
    return false;
}

void calculatePreValue()
{
    memset(vis,false,sizeof(vis));
    queue<pair<pair<int,int>,int>>q;
    for(auto m: monsters)
    {
        q.push({m,0});
        vis[m.first][m.second] = true;
        prevalue[m.first][m.second] = 0;
    }
    while (!q.empty())
    {
        int px = q.front().first.first;
        int py = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();
        for(int i = 0;i<4;i++)
        {
            int nx = px+x[i];
            int ny = py+y[i];
            // if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==false && s[nx][ny]!='#')
            if(isValid(nx,ny))
            {
                vis[nx][ny] = true;
                prevalue[nx][ny]=timer;
                q.push({{nx,ny},timer});
            }
        }
    }
    
}
bool isValidMove(int nx,int ny,int timer)
{
    if(prevalue[nx][ny]>timer)
    {
        return true;
    }
    return false;
}
bool isEscape(int nx,int ny)
{
    if(nx==0 || nx==n-1 || ny==0 || ny==m-1)
    {
        return true;
    }
    return false;
}
void calculatePath(int nx,int ny,pair<int,int>start)
{
    vector<pair<int,int>>path;
    pair<int,int>temp = {nx,ny};
    path.push_back(temp);
    while (parent[temp]!=start)
    {
        temp = parent[temp];
        path.push_back(temp);
    }
    path.push_back(start);
    int sz = path.size();
    for(int i =sz-2;i>=0;i--)
    {
        if(path[i].first>path[i+1].first) ans.push_back('D');
        else if(path[i].first<path[i+1].first) ans.push_back('U');
        else if(path[i].second>path[i+1].second) ans.push_back('R');
        else if(path[i].second<path[i+1].second) ans.push_back('L');

    }
    
}
bool calculatePlayer(pair<int,int>start)
{
    // if(isValidMove(start.first,start.second,0))
    // {
    //     vis[start.first][start.second] = true;
    //     prevalue[start.first][start.second]=0;
        // q.push({{start.first,start.second},timer});
        // parent[{start.first,start.second}] = {px,py};
        if(isEscape(start.first,start.second))
        {
            // calculatePath(start.first,start.second,start);
            return true;
        }
    // }
    memset(vis,false,sizeof(vis));
    queue<pair<pair<int,int>,int>>q;
    q.push({start,0});
    while (!q.empty())
    {
        int px = q.front().first.first;
        int py = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();
        for(int i = 0;i<4;i++)
        {
            int nx = px+x[i];
            int ny = py+y[i];
            // if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==false && s[nx][ny]!='#')
            if(isValid(nx,ny) && isValidMove(nx,ny,timer))
            {
                vis[nx][ny] = true;
                prevalue[nx][ny]=timer;
                q.push({{nx,ny},timer});
                parent[{nx,ny}] = {px,py};
                if(isEscape(nx,ny))
                {
                    calculatePath(nx,ny,start);
                    return true;
                }
            }
        }
    }
    return false;

}
 
void eff()
{
    sff(n,m);
    pair<int,int>playerIndex;
    for(int i = 0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            prevalue[i][j] = 99999999;
            if(s[i][j] == 'M')
            {
                monsters.push_back({i,j});
            }
            if(s[i][j] == 'A')
            {
                playerIndex.first = i;
                playerIndex.second = j;
            }
        }
    }

    calculatePreValue();
    if(!calculatePlayer(playerIndex)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }

}
 
int main()
{
    // freopen ("input.txt","r",stdin);
    // fastio
    ll test = 1;
    // sfl(test);
    for(ll i=0;i<test;i++)
    {
        // printf("Case %lld: ",i+1);
        eff();
    }
    return 0;
}
