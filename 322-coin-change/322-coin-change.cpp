class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
                else
                    break;
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};