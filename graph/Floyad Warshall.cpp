/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
/*
    PROBLEM DESCRIPTION
    Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

    1.Insert
    2.Remove
    3.Replace
    All of the above operations are of equal cost.
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

ll matrix[mx][mx],u,v,w,node,edge;

void floydWarshall()
{
    for(ll k=1;k<=node;k++)
    {
        for(ll i=1;i<=node;i++)
        {
            for(ll j=1;j<=node;j++)
            {
                if(matrix[i][j]>matrix[i][k]+matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    readfile
    //writefile
    cin>>node>>edge;
    for(ll i=0;i<=node;i++)
    {
        for(ll j=0;j<=node;j++)
        {
            if(i==j) matrix[i][j]=0;
            else matrix[i][j]=inf;
        }
    }
    for(ll i=0;i<edge;i++)
    {
        cin>>u>>v>>w;
        matrix[u][v] = w;
    }
    floydWarshall();
    printf("1 4 = %lld\n",matrix[1][4]);
    printf("4 1 = %lld\n",matrix[4][1]);
    printf("3 1 = %lld\n",matrix[3][1]);

}

/*
    INPUT:
    4 6
    4 3 8
    4 1 20
    3 2 5
    2 3 2
    2 1 2
    1 2 3
    OUTPUT:
    1 4 = 100000000
    4 1 = 15
    3 1 = 7
*/
