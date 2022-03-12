class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1&&j==m-1)
                    dp[i][j]=min(0,dungeon[i][j]);
                else if(i==n-1)
                    dp[i][j]=min(0,dungeon[i][j]+dp[i][j+1]);
                else if(j==m-1)
                    dp[i][j]=min(0,dungeon[i][j]+dp[i+1][j]);
                else
                    dp[i][j]=min(0,dungeon[i][j]+max(dp[i+1][j],dp[i][j+1]));
            }
        }
        return 1+abs(dp[0][0]);
    }
};