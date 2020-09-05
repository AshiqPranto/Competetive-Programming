/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/

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
#include<stack>
#include<queue>
#include<deque>

#define ll long long
#define ld long double
#define FOR(x,y) for(ll i=x;i<=y;i++)
#define pb(x) push_back(x)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define vss vector<string>
#define PI (2*acos(0.0))
#define sqr(x) ((x)*(x))
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

using namespace std;

map<char,ll>value;
ll ans;
struct node{
    bool endmark;
    ll numberofend;
    node* next[4];
    node()
    {
        numberofend = 0;
        endmark = false;
        for(ll i=0;i<4;i++)
        {
            next[i] = NULL;
        }
    }
}*root;

void insert(char *str, ll len)
{
    node* curr = root;
    for(ll i=0;i<len;i++)
    {
        ll id = value[str[i]];
        if(curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }
        curr->numberofend++;
        curr = curr->next[id];
    }
    curr->endmark = true;
    curr->numberofend++;
}

bool search(char* str,ll len)
{
    node* curr = root;
    for(ll i=0;i<len;i++)
    {
        ll id = str[i]-'a';
        if(curr->next[id]==NULL)
        {
            return false;
        }
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur)
{
    for(ll i=0;i<4;i++)
    {
        if(cur->next[i])
        {
            del(cur->next[i]);
        }
    }
    delete(cur);
}

void dfs(node* curr,ll maximum)
{
    ans = max(ans,(maximum*curr->numberofend));
    for(ll i=0;i<4;i++)
    {
        if(curr->next[i]!=NULL)
        {
            dfs(curr->next[i],maximum+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //readfile
    //puts("ENTER NUMBER OF WORDS: ");
    value['A'] = 0;
    value['C'] = 1;
    value['G'] = 2;
    value['T'] = 3;
    ll test;
    scanf("%lld",&test);
    for(ll t=1;t<=test;t++)
    {
        root = new node();
        ll num;
        scanf("%lld",&num);
        for(ll i=0;i<num;i++)
        {
            char str[55];
            scanf("%s",str);
            insert(str,strlen(str));
            //printf("%s\n",str);
            //cout<<str<<endl;
        }
        printf("Case %lld: ",t);
        ans=0;
        dfs(root,0);
        printf("%lld\n",ans);
        //cout<<"test case 1 complete\n";
        del(root);

    }
    return 0;
}



/*
    INPUT:
    3 5  //number of coins and the number we need to make
    1 2 3 // coins

    OUTPUT:
    5
*/

