#include<bits/stdc++.h>
using namespace std;


void eff()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<int>dp(n+1,1);
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j= i-1;j>=max(0,i-256);j--)
        {
            if((a[j]^i)<(a[i]^j))
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        eff();
    }
    
}