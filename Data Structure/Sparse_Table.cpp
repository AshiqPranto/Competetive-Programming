const ll N = 100005;
ll st[N][(ll)log2(N)+1];
ll a[N];

void make_sparse_table(ll n){

    f0(n-1) st[i][0] = a[i];

    for(ll j = 1;(1<<j)<=n;j++)
    // for(ll j = 1;j<=log2(n);j++)
    {
        for(ll i = 0;(i+(1<<j)-1)<n;i++)
        {
            st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }

}
ll query(ll low,ll high)
{
    ll total = high-low+1;
    ll j = log2(total);
    return min(st[low][j],st[low+total-(1<<j)][j]);
}