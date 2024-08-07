#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
    int m = q.size();
    vector<int> ans;
    
    vector<int> distances(n);
    for (int i = 0; i < n; i++) {
        distances[i] = n - i - 1;
    }

    vector<int> suffix(n,0);
    suffix[n-1] = distances[n-1];

    for(int i=n-2;i>=0;i--)
    {
        suffix[i] = suffix[i+1] + distances[i];
    }

    for (int i = 0; i < m; i++) {
        int x = q[i][0];
        int y = q[i][1];
        int ct = 1;

        for (int j = x; j >= 0; j--) {
            distances[j] = min(distances[j], distances[y] + ct);
            ct++;
        }

        ans.push_back(distances[0]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> queries;
    int m = 2;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r});
    }

    vector<int> result = shortestDistanceAfterQueries(n, queries);
    for (auto x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
