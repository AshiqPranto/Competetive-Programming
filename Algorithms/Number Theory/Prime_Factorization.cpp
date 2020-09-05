const ll N=1e6+5;
ll prime_factor[N+5];
vector<pair<ll,ll>>prime_factors[N+5];

void prime_Factorization()
{
    for(ll i=2;i<=N;i++)
    {
        if(prime_factor[i]!=0) continue;
        prime_factor[i]=i;
        for(ll j=2*i;j<=N;j+=i) prime_factor[j]=i;
    }
    for(ll i=2;i<=N;i++)
    {
        ll x = i;
        map<ll,ll>M;
        while(x!=1)
        {
            M[prime_factor[x]]++;
            x/=prime_factor[x];
        }
        for(auto v:M) prime_factors[i].push_back(v);
    }
}


