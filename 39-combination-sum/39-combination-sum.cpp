class Solution {
    void solve(vector<vector<int>> &ans,vector<int>& sub,vector<int>& candidates,int target,int ind){
        if(target==0){
            ans.push_back(sub);
            return;
        }
        if(ind==candidates.size())
            return;
        if(candidates[ind]<=target){
            sub.push_back(candidates[ind]);
            solve(ans,sub,candidates,target-candidates[ind],ind);
            sub.pop_back();
        }
        solve(ans,sub,candidates,target,ind+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>sub;
        solve(ans,sub,candidates,target,0);
        return ans;
    }
};