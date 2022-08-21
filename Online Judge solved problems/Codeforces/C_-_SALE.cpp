#include<bits/stdc++.h>
using namespace std;

bool check(int n)
{
    if(n%10 == 9)
    {
        n/=10;
        if(n%10==9){
            return true;

        }

    }
    return false;
}

void eff()
{
    int n;
    cin>>n;
    if(n<100) {
        cout<<99<<endl;
        return;
    }
    else{
        int left,right;
        int temp ;
        for(int i= 1;i<=100;i++)
        {
            temp = n-i;
            if(check(temp))
            {
                left = temp;
            }
            temp = n+i;
            if(check(temp))
            {
                right = temp;
            }
        }
        if((n-left)<(right-n))
        {
            cout<<left<<endl;
        }
        else{
            cout<<right<<endl;
        }
    }

}
int main()
{
    eff();
}