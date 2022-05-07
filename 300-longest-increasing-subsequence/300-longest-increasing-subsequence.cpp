class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && lis[j]>=lis[i]){
                    lis[i]=1+lis[j];
                }
                ans=max(ans,lis[i]);
            }
        }
        return ans;
    }
};