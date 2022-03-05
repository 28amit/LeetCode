class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(10005, 0);
        vector<int> dp(10005, -1);
        
        int maxElement=INT_MIN;
        for(int i=0;i<n;i++) {
            freq[nums[i]]++;
            maxElement = max(maxElement, nums[i]);
        }
        
        return deleteAndEarnUtil(freq, maxElement, dp);
    }
    
    int deleteAndEarnUtil(vector<int> &freq, int i, vector<int> &dp) {
        if(i<=0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        // first case is when we dont pick ith element, second case is when we pick ith element
        int temp = max(deleteAndEarnUtil(freq, i-1, dp), deleteAndEarnUtil(freq, i-2, dp)+freq[i]*i);
        
        dp[i] = temp;
        return dp[i];
    }
};