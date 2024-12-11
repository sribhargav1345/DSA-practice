#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Rotate the array by k places left
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        
        int n = arr.size();
        if(k>n) return;

        int temp[k];
        for(int i=n-k;i<n;i++)
        {
           temp[i-(n-k)] = arr[i];
        }

        for(int i=n-k-1;i>=0;i--)
        {
           arr[i+k] = arr[i];
        }
        
        for(int i=0;i<k;i++)
        {
            arr[i] = temp[i];
        }
    }
};