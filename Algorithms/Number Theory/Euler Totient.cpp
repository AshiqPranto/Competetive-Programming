ll euler_totient(ll n) {
    int root=sqrt(n);
    ll ret=n;
    for(int i=0; i<prime.size() && prime[i]<=root; i++) {
        if(n%prime[i]==0) {
            while(n%prime[i]==0)
                n/=prime[i];
            root=sqrt(n);
            ret-=(ret/prime[i]);
        }
    }
    if(n>1) {
        ret-=(ret/n);
    }
    return ret;
}