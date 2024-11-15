class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0,j = m*n-1;
        int x,y,mid;

        while(i<=j)
        {
            mid = (i+j)/2;

            x = mid / m;
            y = mid % m;

            if(matrix[x][y]==target) return true;

            if(matrix[x][y]> target) j = mid-1;
            else i = mid + 1;
        }
        return false;

    }
};