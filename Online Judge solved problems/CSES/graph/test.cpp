// #counting room problem of graph

#include <bits/stdc++.h>
using namespace std;
int vis[1010][1010] = {0};
string str[1010];
int rooms=0;
int m,n;
void dfs(int i, int j)
{
   
  
   if (i>-1 and i<n and j+1>-1 and j+1<m and vis[i][j + 1] == 0 && str[i][j + 1] != '#')
   {
       vis[i][j+1]=1;
        dfs(i, j + 1);
   }
   if( i>-1 and i<n and j-1>-1 and j-1<m and str[i][j-1] != '#' && vis[i][j-1]==0)
   {
       vis[i][j-1]=1;
        dfs(i, j - 1);
   }
   if( i+1>-1 and i+1<n and j>-1 and j<m and str[i+1][j] != '#' && vis[i+1][j]==0)
   {
      vis[i+1][j]=1;
        dfs(i+1, j);
   }
   if(  i-1>-1 and i-1<n and j>-1 and j<m and str[i-1][j] != '#' && vis[i-1][j]==0)
   {
     vis[i-1][j]=1;
        dfs(i-1, j);
   }
 
}
 
 
int Count(int n, int m)
{
   //cout<<str[1][2];
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < m; j++)
       {
       
           if (str[i][j] != '#' and vis[i][j]==0)
           {
             
             vis[i][j] = 1;
               dfs(i,j);
                rooms++;
           }
       }
    
   }
   return rooms;
}
int main()
{
   cin >> n >> m;
   for (int i = 0; i < n; i++)
   {
       cin >> str[i];
   }
 
  cout<<Count(n,m);
}

