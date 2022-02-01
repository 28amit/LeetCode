class Solution {
    void solve(vector<vector<int>>&ans,vector<int>&ds,int mp[],vector<int>& nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!mp[i]){
                ds.push_back(nums[i]);
                mp[i]=1;
                solve(ans,ds,mp,nums);
                mp[i]=0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int mp[nums.size()];
        for(int i=0;i<nums.size();i++)mp[i]=0;
        solve(ans,ds,mp,nums);
        return ans;
    }
};