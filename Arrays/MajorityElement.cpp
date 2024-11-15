// greater than n/2 times
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;

    vector<ll> arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }
    
    int cnt = 0,el = 0;
    for(int i=0;i<n;i++)
    {   
        if(cnt == 0){
            cnt = 1;
            el = arr[i];
        }
        else if(arr[i] == el)
        {
            cnt++;
        }
        else cnt--; 
    }

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==el) cnt++;
    }

    if(2*cnt > el) return el;
    return -1;
}

// For checking greater than n/3 times
vector<int> solve(vector<int>& arr,int n)
{
    int cnt1 = 0,cnt2 = 0;
    int el1 = 0,el2 = 0;

    for(int i=0;i<n;i++)
    {
        if(cnt1 == 0){
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0){
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(el1 == nums[i]){
            cnt1++;
        }
        else if(el2 == nums[i]){
            cnt2++;
        }
        else 
        {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ls;
    cnt1 = 0,cnt2 = 0;
    for(int i=0;i<n;i++)
    {
        if(el1 == arr[i]) cnt1++;
        if(el2 == arr[i]) cnt2++;
    }

    int mini = (int)(n/3) + 1;
    if(cnt1 >= mini) ls.push_back(cnt1);
    if(cnt2 >= mini) ls.push_back(cnt2);

    return ls;
}