#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

class DistinctValueTree {
public:
    vector<set<int>> seg;

    DistinctValueTree(int n){
        seg.resize(4*n);
    }

    void build(int ind, int low, int high, vector<int>& arr) {

        if (low == high) {
            seg[ind].insert(arr[low]);
            return;
        }

        int mid =(low+high)/2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        // Merge sets
        seg[ind].insert(seg[2*ind+1].begin(),seg[2*ind+1].end());
        seg[ind].insert(seg[2*ind+2].begin(),seg[2*ind+2].end());
    }

    set<int> query(int ind, int low, int high, int l, int r) {
        // Case of No overlap
        if (low > r || high < l) {
            return set<int>(); // Return an empty set
        }

        // Case of complete overlap
        if (low >= l && high <= r) {
            return seg[ind];
        }

        int mid = (low + high) / 2;

        set<int> left = query(2 * ind + 1, low, mid, l, r);
        set<int> right = query(2 * ind + 2, mid + 1, high, l, r);

        // Merge results
        left.insert(right.begin(), right.end());        // We have to return both
        return left;
    }

    void update(int ind, int low, int high, int i, int val, vector<int>& arr) {

        if (low == high) {
            arr[i] = val;
            seg[ind].clear();
            seg[ind].insert(val);

            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid) {
            update(2 * ind + 1, low, mid, i, val, arr);
        } else {
            update(2 * ind + 2, mid + 1, high, i, val, arr);
        }

        seg[ind].clear();

        seg[ind].insert(seg[2*ind+1].begin(),seg[2*ind+1].end());
        seg[ind].insert(seg[2*ind+2].begin(),seg[2*ind+2].end());
    }
};
