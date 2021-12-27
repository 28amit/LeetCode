class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(auto i:nums)
            sum+=i;
        int newtarget=(sum+target)/2;
        if(sum<target||(sum+target)%2!=0||newtarget<0)
            return 0;
        vector<int>dp(newtarget+1, 0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=newtarget;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[newtarget];
    }
};