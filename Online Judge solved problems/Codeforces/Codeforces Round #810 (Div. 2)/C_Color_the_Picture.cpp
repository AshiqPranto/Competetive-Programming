#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long n,m,k;
    long long a[1000005];
    while (t--)
    {
        vector<long long>row,col;
        cin>>n>>m>>k;
        for(int i = 0;i<k;i++)
        {
            cin>>a[i];
            if(a[i]/n >1) row.push_back(a[i]/n);
            if(a[i]/m >1) col.push_back(a[i]/m);
        }
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
        
        int cnt = 0;
        // bool isOdd = false;
        for(int i = 0;i<row.size();i++)
        {
            cnt+=row[i];
            // if(row[i]&1) isOdd = true;
        }
        if(m&1)
        {
            if(row[row.size()-1]>=3)
            {
                cnt-=3;
                // row[row.size()-1] -= 3;
                if(cnt>=m-3)
                {
                    printf("Yes\n");
                    continue;
                }
            }
            // if(cnt>=m && isOdd==true)
            // {
            //     printf("Yes\n");
            //     continue;
            // }
            // else{
            //     printf("No\n");
            //     continue;
            // }
        }
        else{
            if(cnt>=m)
            {
                printf("Yes\n");
                continue;
            }
        }
        cnt = 0;
        // isOdd = false;
        for(int i = 0;i<col.size();i++)
        {
            cnt+=col[i];
            // if(col[i]&1) isOdd = true;
        }
        if(n&1)
        {
            if(col[col.size()-1]>=3)
            {
                cnt-=3;
                // col[col.size()-1] -= 3;
                if(cnt>=n-3)
                {
                    printf("Yes\n");
                    continue;
                }
            }
        }
        else{
            if(cnt>=n)
            {
                printf("Yes\n");
                continue;
            }
        }
        printf("No\n");
    }
    
    
}
