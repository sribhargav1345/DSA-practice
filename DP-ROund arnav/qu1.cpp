long getMinDistance(vector<int> center,vector<int> destination)
{
    int n = center.size();

    sort(center.begin(),center.end());
    sort(destination.begin(),destination.end());

    long ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += abs(destination[i]-center[i]);
    }
    return ans;
}

int getOutlierValue(vector<int> arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(),arr.end(),0);

    sort(arr.begin(),arr.end(),greater<int>());
    unordered_set<int> st(arr.begin(), arr.end());

    for(int i=0;i<n;i++)
    {
        int rem = sum - arr[i];
        if(rem%2 != 0)
        {
            continue;
        }

        int op = rem/2;

        if(st.find(op) != st.end()) 
        {
            return arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }
    return -1;
}