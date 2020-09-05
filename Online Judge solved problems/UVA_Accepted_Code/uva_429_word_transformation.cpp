
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
#include <stack>
#include<queue>
#include<deque>
#include<bits/stdc++.h>

#define ll long long
#define ld long double
#define pb(x) push_back(x)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define PI (2*acos(0.0))
#define sqr(x) ((x)*(x))
#define FOR(start,end) for(ll i=start;i<=end;i++)
#define readfile freopen("input.txt","r",stdin);
#define writefile freopen("output.txt","w",stdout);
//#define mx 100
#define inf 1000000

using namespace std;

map<ll,vector<string> >words;
map<string,ll>level;

void bfs(string source)
{
    queue<string>q;
    q.push(source);
    level[source]=0;
    while(!q.empty())
    {
        string top = q.front();
        ll toplen = top.length();
        q.pop();
        for(ll i=0;i<words[toplen].size();i++)
        {
            string node=words[toplen][i];
            if(level[node]==0 && node!=source)
            {
                ll dif=0;
                for(ll j=0;j<top.length();j++)
                {
                    if(top[j]!=node[j]) dif++;
                }
                if(dif==1)
                {
                    q.push(node);
                    level[node]=level[top]+1;
                }
                //cout<<"dif = "<<dif<<" "<<top<<" "<<node<<endl;

            }
        }
    }
}

int main()
{
    //readfile
    //writefile
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
        //cout<<n<<endl;
        for(ll z=1;z<=n;z++)
        {
            string s;
            while(cin>>s)
            {
                //cout<<s<<endl;
                if(s=="*") break;
                words[s.length()].pb(s);
                //level[s]=-1;
            }
            cin.ignore();
            string fullline,a,b;
            while(getline(cin,fullline) && fullline!="")
            {
                //cout<<fullline<<endl;
                stringstream str(fullline);
                str>>a>>b;
                //fill(level.begin(),level.end(),-1);
                bfs(a);
                cout<<a<<" "<<b<<" "<<level[b]<<endl;
                //cout<<"level of a = "<<level[a]<<endl;
                level.clear();
            }
            if(z!=n) cout<<endl;
            words.clear();
        }
        //level.clear();


}
