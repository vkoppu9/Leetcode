/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x = grid.size(); 
        if(x == 0) 
            return 0;
        int y = grid[0].size();
        vector<vector<int>> dp(x, vector<int> (y));
        
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(i > 0 and j > 0) 
                    grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
                else if(i == 0 and j > 0) 
                    grid[i][j] += grid[i][j-1];
                else if(i > 0 and j == 0) 
                    grid[i][j] += grid[i-1][j];
            }
        }
        /*for(int i = 0; i < x; i++) { 
            for(int j = 0; j < y; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }*/
        return grid[x-1][y-1];
    }
};
/*
taking dp matrix
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = grid[0][0];
    for(int i=1;i<m;i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for(int j=1;j<n;j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];
     for(int i=1;i<m;i++)
         for(int j=1;j<n;j++)
             dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        return dp[m-1][n-1];
    }
*/
