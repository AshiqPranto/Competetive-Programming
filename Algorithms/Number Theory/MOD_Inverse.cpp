/* There have two ways to calculate mod inverse. One is using Fermat's Little theorem, which is using big mod(power()).
and another one is using extended_euclide algo.Below is given both implementation
*/
ll modInv(ll n,ll mod)
{
    return power(n,mod-2);
}

ll modInv(ll n,ll mod)
{
    ll x,y;
    ext_gcd(n,mod,x,y);
    x = MOD(x,mod);
    if(x<0) x+=mod;
    return x;
}