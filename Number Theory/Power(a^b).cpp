

ll power(ll a,ll b)
{
    ll ans = 1;
    while(b>=1)
    {
        if(b&1)
        {
            ans = (ans*a)%mod;
            a = (a*a)%mod;
            b/=2;
        }
        else
        {
            a = (a*a)%mod;
            b/=2;
        }
    }
    return ans;
    
}
ll power(ll a,ll b)
{
    if(b==0) return 1;
    ll temp = power(a,b/2);
    if(b&1)
    {
        return (((temp*temp)%mod)*a)%mod;
    }
    else
    {
        return (temp*temp)%mod;
    }
    
}
