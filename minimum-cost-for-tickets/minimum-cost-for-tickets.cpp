class Solution {
public:
    int n;
    unordered_set<int>s;
    int solve(vector<int>& days, vector<int>& costs,int cday,vector<int>& dp){
        if(cday>days[n-1])
            return dp[cday]=0;
        if(dp[cday]!=-1)
            return dp[cday];
        int ans=INT_MAX;
        if(s.count(cday)){
            ans=solve(days,costs,cday+1,dp)+costs[0];
            ans=min(ans,solve(days,costs,cday+7,dp)+costs[1]);
            ans=min(ans,solve(days,costs,cday+30,dp)+costs[2]);
        }
        else
            return dp[cday]=solve(days,costs,cday+1,dp);
        return dp[cday]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        vector<int>dp(days[n-1]+31,-1);
        for(int i=0;i<n;i++){
            s.insert(days[i]);
        }
        return solve(days,costs,0,dp);
    }
};