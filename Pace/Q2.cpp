#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int idx, vector<int>& v, vector<int>& color, int n) {
    if (idx == n) {
        return 1; 
    }

    ll count = 0;
    for (int j = 0; j < 3; j++){
        if (idx > 0 && v[idx - 1] == color[j]) continue; 
        if (2*idx>n && v[n-idx-1] == color[j]) continue; 

        v[idx] = color[j]; 
        count += f(idx + 1, v, color, n); 
        v[idx] = 0;
    }

    return count;
}

int solve(int n) {
    vector<int> v(n, 0);
    vector<int> color = {1, 2, 3}; 
    return f(0, v, color, n);
}

int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}


// dp sol:

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int solve(int n) {
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(4, vector<ll>(4, -1)));
    vector<int> colors = {1, 2, 3};

    function<ll(int, int, int)> f = [&](int idx, int prev, int opposite) {
        if (idx == n) return 1LL; 
        if (dp[idx][prev][opposite] != -1) return dp[idx][prev][opposite];

        ll count = 0;
        for (int color : colors) {
            if (color == prev) continue; // Adjacent constraint
            if (2 * idx > n && color == opposite) continue; // Equidistant constraint
            count = (count + f(idx + 1, color, (2 * idx > n ? -1 : (n - idx - 1 >= 0 ? color : -1)))) % MOD;
        }

        return dp[idx][prev][opposite] = count;
    };

    // Start recursion
    return f(0, 0, 0);
}

int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
