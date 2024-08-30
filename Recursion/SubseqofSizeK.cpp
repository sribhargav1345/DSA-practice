#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(int id,int n,vector<int>& arr,int k,int sum){
    if(sum == k) return true;
    if(id == n || sum>k) return false;

    if (solve(id + 1, n, arr, k, sum + arr[id])) return true;
    if (solve(id + 1, n, arr, k, sum)) return true;

    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    if(solve(0,n,a,k,0)) return true;
    return false;
}