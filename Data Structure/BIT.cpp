struct BIT
{
    ll sz;
    vector<ll>a;

    void init(ll n)
    {
        sz = n;
        a = vector<ll>(n+1,0);
    }

    void update(ll index,ll x)
    {
        if(index<=0) return;
        while(index<=sz)
        {
            a[index]+=x;
            index+=index&(-index);
        }
    }

    ll query(ll index)
    {
        ll sum = 0;
        while(index>0)
        {
            sum+=a[index];
            index-=index&(-index);
        }
        return sum;
    }
    // bit's are 1 indexed, be carefull

};