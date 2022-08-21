#include<bits/stdc++.h>
using namespace std;

bool check(string a,string b)
{
    int n=a.size();
    int m=b.size();
    if(m==1) return true;
    for(int i = m-1,j = n-1;i>=1;i--,j--)
    {
        if(a[j]!=b[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    string a,b;
    int n,m;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        cin>>a>>b;
        if(check(a,b))
        {
            bool tracker = false;
            int sz = n-m;
            if(m==1) sz = n;
            for(int i = 0;i<sz;i++)
            {
                if(a[i]==b[0])
                {
                    tracker = true;
                    printf("YES\n");
                    break;
                }
            }
            if(!tracker)
                printf("NO\n");
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
}