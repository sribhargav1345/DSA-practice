#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(long long arr1[], long long arr2[], int n, int m) {

    vector<int> ans(n+m);
    int left = 0,right = 0;

    int ct = 0;

    while(left<n && right<m)
    {
        if(arr1[left]<=arr2[right])
        {
            ans[ct] = arr1[left];
            left++;
            ct++;
        }
        else if(arr1[left]>arr2[right])
        {
            ans[ct] = arr2[right];
            right++;
            ct++;
        }
    }

    while(left<n)
    {
        ans[ct] = arr1[left];
        ct++;
        left++;
    }
    while(right<m)
    {
        ans[ct] = arr2[right];
        ct++;
        right++;
    }
}

void merge(vector<int>& arr1,vector<int>& arr2,int n,int m)
{
    int len = n+m;
    int gap = (len/2) + (len%2);

    while(gap>0)
    {
        int left = 0;
        int right = gap+left;

        while(right<len)
        {
            if(left<n && right>=n){
                if(arr1[left]>arr2[right-n])
                {
                    swap(arr1[left],arr2[right-n]);
                }
            }

            else if(right<n){
                if(arr1[left]>arr2[right])
                {
                    swap(arr1[left],arr2[right]);
                }
            }

            else if(left>=n){
                if(arr2[left-n]>arr2[right-n]){
                    swap(arr2[left-n],arr2[right-n]);
                }
            }

            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    }
}