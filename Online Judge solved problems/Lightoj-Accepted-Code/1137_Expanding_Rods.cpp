#include<bits/stdc++.h>
using namespace std;

double n,c,l,s;

double func(double H)
{
    double r,a;
    double b = H;
    double c= l*0.5;
    r = b/2+(c*c/(2*b));
    a = 2*asin(c/r);
    return r*a;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lf%lf%lf",&l,&n,&c);

        s = (1.0+(n*c))*l;

        double st = 0,end = l,mid;
        for(int i=0;i<60;i++)
        {
            mid = (st+end)/2;
            if(func(mid)>s) end = mid;
            else st = mid;
        }
        printf("Case %d: %0.8lf\n",i,mid);
    }
}