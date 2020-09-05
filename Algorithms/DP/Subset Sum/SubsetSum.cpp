ll subsetSum(vll value,ll amount)
{
    //Memory Reduction,each coin once time,iterative dp
    ll dp[amount+1];
    ll sz = value.size();
    for(ll j=1;j<=amount;j++) dp[j] = 0;
    dp[0] = 1;
    for(ll i=0;i<sz;i++)
    for(ll j=amount;j>=value[i];j--)
    {
        dp[j]+=dp[j-value[i]];
    }
    return dp[amount];
}

ll make(ll i,ll amount)
{
    //dp solution
    if(amount==0) return 1;
    if(amount<0 || i>=coin.size) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];
    ll r1 = 1+make(i+1,amount-coin[i]);//we will not repeat a coin
    // ll r1 = make(i,amount-coin[i]); // we may take the same coin again
    ll r2 = make(i+1,amount);
    return dp[i][amount] = r1+r2;
}

ll make(vll coins,ll amount)
{
    //Memory Reduction, Each coin unlimited time, Iterative dp
    ll dp[amount+1],sz = coins.size();
    for(ll j=1;j<=amount;j++) dp[j] = 0;
    dp[0] = 1;
    for(ll i=0;i<sz;i++)
    {
        for(ll j=coins[i];j<=amount;j++)
        {
            dp[j] += dp[j-coins[i]];
        }
    }
    return dp[amount];
}