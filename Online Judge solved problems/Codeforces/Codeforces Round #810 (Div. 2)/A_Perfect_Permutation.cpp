#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        if(n&1)
        {
            printf("1 ");
            for(int i = 3;i<=n;i+=2)
            {
                printf("%d %d ",i,i-1);
            }
        }
        else{
            for(int i = 2;i<=n;i+=2)
            {
                printf("%d %d ",i,i-1);
            }
        }
        cout<<endl;
    }
}