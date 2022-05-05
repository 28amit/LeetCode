class Solution {
public:
    vector<int>dp=vector<int>(46,0);
    int climbStairs(int n) {
        if(n==1||n==0||n==2)
            return n;
        if(dp[n]!=0)
            return dp[n];
        return dp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};