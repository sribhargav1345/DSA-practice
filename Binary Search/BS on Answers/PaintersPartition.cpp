#include<bits/stdc++.h>
using namespace std;

// Same as split array largest sum
int f(vector<int>& boards,int mid,int n)
{
    int sum = 0;
    int ct = 1;

    for(int i=0;i<n;i++)
    {
        if(sum+boards[i]>mid){
            ct++;
            sum = boards[i];
        }
        else sum += boards[i];
    }
    return ct;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();

    int low = *max_element(boards.begin(),boards.end());

    int high = 0;
    for(auto x:boards) high += x;

    while(low<=high)
    {
        int mid = ((low+high)/2);

        if(f(boards,mid,n) <= k) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}