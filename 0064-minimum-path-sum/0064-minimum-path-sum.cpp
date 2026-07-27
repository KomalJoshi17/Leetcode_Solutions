class Solution {
public:
    int solve(int m,int n, vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(m<0 || n<0) return 1e9;
        if(m==0 && n==0) return grid[m][n];

        if(dp[m][n]!=-1) return dp[m][n];

        int right=solve(m,n-1,grid,dp)+grid[m][n];
        int down=solve(m-1,n,grid,dp)+grid[m][n];

        return dp[m][n]=min(right,down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};