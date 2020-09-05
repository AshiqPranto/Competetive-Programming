const int N = 1e7+5;
bool composite[N];
vll prime;

void sieve()
{
    for(ll i=2;i<=N;i++)
    {
        if(composite[i]) continue;
        prime.pb(i);
        composite[i]=1;
        for(ll j=i+i;j<=N;j+=i) composite[j]=1;
    }
}