class Solution {
    void solve(vector<vector<int>>& ans,vector<int>& sub,vector<int>& nums,int ind){
        ans.push_back(sub);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind&&nums[i]==nums[i-1]) continue;
            sub.push_back(nums[i]);
            solve(ans,sub,nums,i+1);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        sort(nums.begin(),nums.end());
        solve(ans,sub,nums,0);
        return ans;
    }
};