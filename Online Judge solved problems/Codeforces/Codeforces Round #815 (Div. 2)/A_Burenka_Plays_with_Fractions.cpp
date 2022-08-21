#include<bits/stdc++.h>
using namespace std;


void eff()
{
    long long a,b,c,d,gcd;
    cin>>a>>b>>c>>d;
    if(a==0 && c==0)
    {
        cout<<0<<endl;
        return;
    }
    else if(a==0 || c==0)
    {
        cout<<1<<endl;
        return;
    }
    while(__gcd(a,b)!=1)
    {
        gcd = __gcd(a,b);
        a/=gcd;
        b/=gcd;
    }
    while(__gcd(c,d)!=1)
    {
        gcd = __gcd(c,d);
        c/=gcd;
        d/=gcd;
    }
    if(a==c && b==d)
    {
        cout<<0<<endl;
        return;
    }
    if(((b*c)/(a*d))*(a*d) == (b*c))
    {
        cout<<1<<endl;
        return;
    }
    else if(((a*d)/(b*c))*(b*c) == (a*d))
    {
        cout<<1<<endl;
        return;
    }
    else{
        cout<<2<<endl;
        return;
    }
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