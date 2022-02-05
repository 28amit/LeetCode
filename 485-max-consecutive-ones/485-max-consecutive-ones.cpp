class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,tmp=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                tmp++;
            else{
                ans=max(ans,tmp);
                tmp=0;
                }
        }
        return max(ans,tmp);
    }
};