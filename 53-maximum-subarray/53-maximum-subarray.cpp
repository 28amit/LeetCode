class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int tmp=0;
        for(int i=0;i<nums.size();i++){
            tmp+=nums[i];
            if(tmp>ans)
                ans=tmp;
            if(tmp<0)
                tmp=0;
        }
        return ans;
    }
};