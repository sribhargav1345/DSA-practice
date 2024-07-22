#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt = 0;        // Change from merge sort code

void merge(vector<ll>& arr, int low,int mid, int high){
    vector<ll> temp;

    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else 
        {
            temp.push_back(arr[right]);
            cnt += (mid-left+1);          // Change from merge sort code, we are only adding left array's part
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++)
    {
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<ll>& arr,int low,int high){
    if(low >= high) return;

    int mid = (low+high)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    merge(arr,low,mid,high);
}

int main(){
    int n;
    cin>>n;

    vector<ll> arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }
    
    mergeSort(arr,0,n-1);
}