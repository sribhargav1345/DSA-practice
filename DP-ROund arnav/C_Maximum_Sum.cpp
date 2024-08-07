#include <bits/stdc++.h>
using namespace std;

/* <-------- Based on Taking inputs ---------> */
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long int

/* Min-heap, if u forgot ->   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  */
/*Now you can use mod_int for long number ones, but remember at last u have to return ans.value*/

/* <----------- Constants ----------> */
const ll mod = 1e9 + 7;
const ll inf = 1e10;

struct mod_int {

    int value;

    mod_int(int initial) : value(initial) {}

    mod_int operator+(const mod_int &other) const {
        return (value + other.value) % mod;
    }

    mod_int operator-(const mod_int &other) const {
        return (value - other.value + mod) % mod;
    }

    mod_int operator*(const mod_int &other) const {
        return (static_cast<long long>(value) * other.value) % mod;
    }
};

void sieveOfEratosthenes(int n, std::vector<bool>& primes) {
    primes.assign(n + 1, true);
    primes[0] = primes[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (primes[p]) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
       }
    }
}


int popo(int n)
{
    return (__builtin_popcount(n));
}

static bool compare(pair<int,int>& a, pair<int,int>& b)
{
    if(a.first==b.first) return (a.second>b.second);
    return (a.first<b.first);        // Once check this compare function if needed
}


bool isPrime(int n){
    if(n==1) return false;
    else
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
         return true;
    }
}

int bitsToNum(vector<int>& bits) {
     int result = 0;
     for (int i = 0; i < 32; i++) {
         if (bits[i]) {
             result |= 1 << i;
         }
     }
     return result;
}


void print(vector<ll>& arr){
    for(auto x:arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

/* <------------ Codeforces, Codechef Model ------------> */
void solvepro()
{
    // Code here, int1 for taking 1 input, int4 for 4 inputs, vecin for vector taking
    // for loop -> forn, sum of all array ele -> allsum, prefixsum -> prefixsum, st1 -> takestring

    ll n,k;
    cin>>n>>k;

    vector<ll> arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
    
        arr.push_back(x);
    }
    
    // First perform Kadane
    ll maxi = 0;
    ll sum = 0;

    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(sum>maxi) maxi = sum;

        if(sum<0) sum = 0;
    }

    //cout<<"sum"<<maxi<<endl;

    ll mod = 1e9 + 7;

    if(maxi == 0) 
    {
        sum = accumulate(arr.begin(),arr.end(),0);
        ll ans = (sum)%mod + mod;

        cout<<ans<<endl;
    }
    else
    {
        vector<ll> dp(k+2,0);
        dp[0] = accumulate(arr.begin(),arr.end(),0);
        dp[1] = dp[0] + maxi;

        for(int i=2;i<=k;i++)
        {
            dp[i] = (dp[i-1] + maxi*2)%mod;
            dp[i] = dp[i]%mod;

            maxi = maxi*2;
            maxi = maxi%mod;
        }
        ll ok = dp[k]%mod;

        cout<<ok<<endl;
    }
}


int main() 
{
    FAST;
 
    ll t;
    cin>>t;

    while(t--)
    {
        solvepro();
    }
    return 0;
}
 
// Author: sribhargav1345