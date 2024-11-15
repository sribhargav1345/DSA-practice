#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s){
    int n = s.size();
    int ct = 0;

    int flag = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') ct++;
        else ct--;

        if(ct<0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return false;
    }
    return (ct==0);
}

int f(string s){
    int n = s.size();

    for(int i=0;i<n;i++)
    {
        if(s[i]=='0') return i;
    }
    return -1;
}

int main()
{
    string s;
    cin>>s;
    
    string ans = s;

    int n = s.size();
    for(int i=0;i<n;i++)
    {
        string p = s.substr(0,i+1);
        string q = s.substr(i+1,n-i-1);

        if(solve(p) && solve(q)){
            
            string ko = q;
            for(auto x:p) ko += x;

            if(f(ans)<f(ko)){
                ans = ko;
            }
        }
    }
    cout<<ans<<endl;
}