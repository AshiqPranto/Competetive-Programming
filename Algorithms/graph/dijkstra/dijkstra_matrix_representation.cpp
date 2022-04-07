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

//#include<bits/stdc++.h>

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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mx 1009
#define inf 1000000
#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

ll connection[mx][mx],dis[mx];
ll vertex,edge;

struct node
{
    ll currentNode;
    ll parent;
ll color;
    ll costMin;

    bool operator<(const node& temp) const
    {
        return costMin>temp.costMin;
    }
};
node itemList[mx];
priority_queue<node>queueVertex;

void setAll(ll startingNode)
{
    dis[startingNode]=0;
    itemList[startingNode].costMin=0;
    itemList[startingNode].parent=startingNode;
    itemList[startingNode].color=WHITE;
    itemList[startingNode].currentNode=startingNode;
    for(ll i=1;i<=vertex;i++)
    {
        if(i!=startingNode)
        {
            dis[i]=inf;
            itemList[i].currentNode=i;
            itemList[i].costMin=inf;
            itemList[i].parent=-1;
            itemList[i].color=WHITE;
        }
    }
}

void dijkstra(ll startingNode)
{
    setAll(startingNode);
    queueVertex.push(itemList[startingNode]);
    while(!queueVertex.empty())
    {

        node current=queueVertex.top();
        queueVertex.pop();

        if(current.color==WHITE)
        {

            for(ll i=1;i<=vertex;i++)
            {

                if(connection[current.currentNode][i]!=0)
                {
                    //cout<<"check1"<<endl;
                    if(itemList[i].costMin>(current.costMin+connection[current.currentNode][i]))
                    {
                        //cout<<"check"<<endl;
                        itemList[i].costMin=current.costMin+connection[current.currentNode][i];
                        itemList[i].parent=current.currentNode;
                        queueVertex.push(itemList[i]);
                    }
                }
            }
        }
        itemList[current.currentNode].color=BLACK;
    }

    return;
}
int main()
{
    //readfile
    //fastio;
    cin>>vertex>>edge;
    ll node1,node2,w;
    while(edge--)
    {
        cin>>node1>>node2>>w;
        if(connection[node1][node2]==0)
        {
            connection[node1][node2]=w;
            //cout<<connection[node1][node2]<<endl;
        }
        else
        {
            connection[node1][node2]=min(w,connection[node1][node2]);
        }
    }

    dijkstra(1);

    //cout<<itemList[5].parent;
    vll store;
    for(ll i=vertex;itemList[i].parent!=i;i=itemList[i].parent)
    {
        store.pb(i);
    }
    cout<<1<<" ";
    //cout<<store.size()<<endl;
    for(ll i=store.size()-1;i>=0;i--) cout<<store[i]<<" ";
    //cout<<endl;

}
