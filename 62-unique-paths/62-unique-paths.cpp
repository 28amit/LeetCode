class Solution {
public:
    int solve(int i, int j,int m, int n,vector<vector<int>>&dp){
        if(i==n-1&&j==m-1)
            return 1;
        else if(i>=n||j>=m)
            return 0;
        else{
            if(dp[i][j]!=-1)
                return dp[i][j]; 
            return dp[i][j]=solve(i,j+1,m,n,dp)+solve(i+1,j,m,n,dp);
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,m,n,dp);
    }
};