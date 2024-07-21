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

void merge(vector<int>& count,vector<pair<int,int>>& v,int left,int mid,int right)
{
    vector<pair<int,int>> temp(right-left+1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i<=mid && j<=right){
        if(v[i].first <= v[j].first){
            temp[k++] = v[j++];
        }
        else
        {
            count[v[i].second] += (right-j+1);
            temp[k++] = v[i++];
        }
    }

    while(i<=mid) temp[k++] = v[i++];
    while(j<=right) temp[k++] = v[j++];

    for (int i = left; i <= right; i++)
        v[i] = temp[i-left];
}

void mergeSort(vector<int>& count,vector<pair<int,int>>& v, int left, int right){
    if(left >= right) return;

    int mid = (left+right)/2;
    mergeSort(count,v,left,mid);
    mergeSort(count,v,mid+1,right);
    
    merge(count,v,left,mid,right);
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();

    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        v[i] = {nums[i],i};
    }

    vector<int> count(n,0);
    mergeSort(count,v,0,n-1);

    return count;
}

/* <------------ Codeforces, Codechef Model ------------> */
void solvepro()
{
    // Code here, int1 for taking 1 input, int4 for 4 inputs, vecin for vector taking
    // for loop -> forn, sum of all array ele -> allsum, prefixsum -> prefixsum, st1 -> takestring

    ll n;
    cin>>n;

    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
    
        arr.push_back({x,y});
    }

    // Basically, we have to count smaller elements to the right of arr[i].second for each index
    sort(arr.begin(),arr.end());

    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(arr[i].second);
    }

    vector<int> p = countSmaller(v);
    ll sum = 0;
    for(auto x:p)
    {
        sum += x;
    }
    cout<<sum<<endl;

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