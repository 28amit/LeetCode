class Solution {
public:
    void solve(vector<int>& sub,vector<vector<int>>&ans,vector<int>& nums,int i){
        if(i>=nums.size()){
            ans.push_back(sub);
            return;
        }
        solve(sub,ans,nums,i+1);
        sub.push_back(nums[i]);
        solve(sub,ans,nums,i+1);
        sub.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>sub;
        vector<vector<int>>ans;
        solve(sub,ans,nums,0);
        return ans;
    }
};