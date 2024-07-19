#include<bits/stdc++.h>
using namespace std;

long long f(vector<int>& arr,int n,int mid){
    long long ans = 1;
    long long sum = 0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]> mid)
        {
            ans++;
            sum = arr[i];
        }
        else sum += arr[i];
    }
    return ans;
}

int findPages(vector<int>& arr, int n, int m) {
    
    if(m>n) return -1;

    // First find the range of answer

    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low<=high)
    {
        int mid = (low+high)/2;

        if(f(arr,n,mid)<=m) high = mid-1;
        else low = mid+1;
    }
    return low;
}