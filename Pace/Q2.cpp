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
