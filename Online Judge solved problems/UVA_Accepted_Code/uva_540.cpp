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
#define mx 100005
#define inf 100005

using namespace std;

int main()
{
    //readfile
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,x;
    string s;
    ll test=0;
    while(cin>>t && t!=0)
    {
        printf("Scenario #%lld\n",++test);
        map<ll,ll>teamnumber;
        queue<ll>seq;
        queue<ll>teams[1005];
        for(ll i=0;i<t;i++)
        {
            cin>>n;
            while(n--)
            {
                cin>>x;
                teamnumber[x]=i;
            }
        }
        while(cin>>s && s[0]!='S')
        {
            if(s[0]=='E')
            {
                cin>>n;
                if(teams[teamnumber[n]].empty())
                {
                    seq.push(teamnumber[n]);

                }
                teams[teamnumber[n]].push(n);
            }
            else
            {
                ll tm=seq.front();
                cout<<teams[tm].front()<<endl;
                teams[tm].pop();
                if(teams[tm].empty())
                {
                    seq.pop();
                }
            }
        }
        cout<<endl;
    }

}
