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
    Source: https://www.geeksforgeeks.org/edit-distance-dp-5/
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
#define writefile freopen("output.txt","w",stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define gap " "
#define mx 1000
#define inf (ll)1e9
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define EMPTY_VALUE -1

using namespace std;

ll fx[4]={-1,+1,0,0},fy[4]={0,0,+1,-1};
ll mem[mx][mx];

ll editDistance(string word1,string word2,ll m,ll n)
    {
        if(m==0) return n;
        if(n==0) return m;
        if(mem[m][n]!=EMPTY_VALUE) return mem[m][n];
        if(word1[m-1]== word2[n-1]) return mem[m][n] = editDistance(word1,word2,m-1,n-1);

        return mem[m][n] = 1+min(editDistance(word1,word2,m,n-1),min(editDistance(word1,word2,m-1,n),editDistance(word1,word2,m-1,n-1)));
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    readfile
    //writefile
    string s,w;
    memset(mem,-1,sizeof(mem[0][0])*mx*mx);
    cin>>s>>w;
    cout<<editDistance(s,w,s.size(),w.size())<<endl;
}

/*
    INPUT:
    geek
    gesek
    OUTPUT:
    1

*/

