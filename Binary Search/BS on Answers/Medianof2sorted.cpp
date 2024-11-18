// Brute force is similar to merge sort

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        if(n>m) return findMedianSortedArrays(b,a);

        int op = n+m;
        int left = (n+m+1)/2;

        int low = 0,high = n;
        while(low<=high)
        {
            int mid1 = (low+high)/2;
            int mid2 = left - mid1;     // 2nd array elements will be left-first elements

            long int l1 = INT_MIN;
            long int l2 = INT_MIN;

            long int r1 = INT_MAX;
            long int r2 = INT_MAX;

            if(mid1<n) r1 = a[mid1];
            if(mid2<m) r2 = b[mid2];

            if(mid1>=1) l1 = a[mid1-1];
            if(mid2>=1) l2 = b[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(op%2 == 1){
                    return ((double)max(l1,l2));
                }
                else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if(l1>r2) high = mid1-1;
            else low = mid1+1;
        }
        return -1;
    }
};