class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int tmp=target-nums[i];
            if(mp.count(tmp)>0){
                return {i,mp[tmp]};
            }
            mp[nums[i]]=i;
        }
        return {-1};
    }
};