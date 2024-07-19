#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int lb = lower_bound(arr,arr+n,x) - arr;
	    int ub = upper_bound(arr,arr+n,x) - arr;
	    
	    return (ub-lb);
	    
	}
};