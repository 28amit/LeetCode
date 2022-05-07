class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis;
        lis.push_back(nums[0]);
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]>lis.back()){
                lis.push_back(nums[i]);
                ans++;}
            else{
                int tmp=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                lis[tmp]=nums[i];
            }
        }
        return ans;
    }
};