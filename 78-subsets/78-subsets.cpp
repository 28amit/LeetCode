class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int len=1<<n;
        vector<vector<int>>ans(len);
        for(int i=0;i<len;i++){
            for(int j=0;j<n;j++){
                if((i>>j)&1)
                    ans[i].push_back(nums[j]);
            }
        }
        return ans;
    }
};