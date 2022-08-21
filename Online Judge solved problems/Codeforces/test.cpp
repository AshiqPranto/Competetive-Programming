#include<bits/stdc++.h>
using namespace std;

string int_to_binary(int n)
{
    string ans = "";
    while(n>0)
    {
        if(n&1)
            ans+='1';
        else
            ans+='0';
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{
    string s ;
    // cin>>s;
    int n;
    cin>>n;
    string ans = int_to_binary(n);
    cout<<ans<<endl;
    // string sub = substr(ans.begin(),ans.end());
    string sub = ans.substr(2);
    cout<<sub<<endl;
}