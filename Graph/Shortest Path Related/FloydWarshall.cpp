#include<bits/stdc++.h>
using namespace std;

// O(n**3) solution, just iterating the whole matrix and finding min of matrix[i][k] + matrix[k][j]
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    int m = matrix[0].size();
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(i==j) matrix[i][j] = 0;
	            else if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	        }
	    }
	    
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	        }
	    }
	}
};