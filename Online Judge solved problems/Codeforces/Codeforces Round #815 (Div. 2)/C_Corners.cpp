#include<bits/stdc++.h>
using namespace std;

int x[8] = {1,-1,0,0,1,1,-1,-1};
int y[8] = {0,0,1,-1,1,-1,-1,1};

void eff()
{
    int n,m,totalOne = 0;
    cin>>n>>m;
    string a[n+5];
    // int a[n+5][m+5];
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        for(int j = 0;j<m;j++)
        {
            if(a[i][j] == '1')
            {
                totalOne++;
            }
        }
    }
    // cout<<"total one = "<<totalOne<<endl;
    if(totalOne==0) {
        cout<<0<<endl;
        return;
    }
    int onezero = 0;
    int twozero = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(a[i][j]=='0')
            {
                onezero = 1;
                for(int k = 0;k<8;k++)
                {
                    if((i+x[k]<n) && (i+x[k]>=0) && (j+y[k]<m) && (j+y[k]>=0) &&(a[i+x[k]][j+y[k]]=='0'))
                    {
                        twozero = 1;
                        cout<<totalOne<<endl;
                        return;
                    }
                }
            }
        }
    }
    if(onezero == 1)
    {
        cout<<totalOne-2+1<<endl;
        return;
    }
    else{
        cout<<totalOne-3+1<<endl;
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