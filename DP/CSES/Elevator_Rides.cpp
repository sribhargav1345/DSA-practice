#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, x;
    cin >> n >> x;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<pair<ll, ll>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, 0}; // we need 1 ride with 0 space used for no items

    for (ll mask = 0; mask < (1 << n); mask++) {
        for (ll i = 0; i < n; i++) {
            if (mask & (1 << i)) continue; // i is already in current mask

            ll next_mask = mask | (1 << i);
            auto [rides, remaining] = dp[mask];

            if (remaining + arr[i] <= x) {
                dp[next_mask] = min(dp[next_mask], {rides, remaining + arr[i]});
            } else {
                dp[next_mask] = min(dp[next_mask], {rides + 1, arr[i]});
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;
}
