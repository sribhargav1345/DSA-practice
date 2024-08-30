bool helper(vector<int>& A, int N, int M, int L, int X) {
    vector<int> diff(N + 1, 0);
    int queries = 0;
    
    for (int i = 0; i < N; ++i) {
        if (i > 0) diff[i] += diff[i - 1];
        int current = A[i] + diff[i];
        
        if (current > X) {
            int decrement = current - X;
            queries += decrement;
            if (queries > M) return false;
            
            diff[i] -= decrement;
            if (i + L < N) diff[i + L] += decrement;
        }
    }
    return true;
}
 

int solve(vector<int>& A, int N, int M, int L) {
    int low = *min_element(A.begin(), A.end()) - m;
    int high = *max_element(A.begin(), A.end());
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (helper(A, N, M, L, mid))  high = mid;
        else    low = mid + 1;
    }
    
    return low;
}

int main()
{
    
}