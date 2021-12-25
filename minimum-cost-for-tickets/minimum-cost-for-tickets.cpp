class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(400);
        unordered_set s(days.begin(),days.end());
        for(int i=1;i<366;i++){
            dp[i]=dp[i-1];
            if(s.count(i)){
                dp[i]=min({dp[i-1]+costs[0],dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]});
            }
        }
        return dp[365];
    }
};