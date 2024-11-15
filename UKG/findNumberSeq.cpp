#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> findNumberSequence(string s,int n)
{
    int low = 0;
    int high = pow(2,n);

    vector<int> ans;

    int ct = 0;
    while(ct<n && low<=high)
    {
        int mid = (low + high)/2;
        if(s[ct] == 'L'){
            high = mid;
            ans.push_back(mid);
        }
        else
        {
            low = mid;
            ans.push_back(mid);
        }
        ct++;
    }
    return ans;
}

int main()
{
    ll n;
    cin>>n;

    string s;
    cin>>s;

    for(auto x:findNumberSequence(s,n)){
        cout<<x<<" ";
    }
    cout<<endl;
}