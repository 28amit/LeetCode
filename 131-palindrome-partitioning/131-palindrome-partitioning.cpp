class Solution {
public:
    bool isPal(string s,int start,int e){
        while(start<=e){
            if(s[start++]!=s[e--])
                return 0;
        }
        return 1;
    }
    void solve(vector<vector<string>>&ans,vector<string>&res,string &s,int ind){
        if(ind==s.size()){
            ans.push_back(res);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPal(s,ind,i)){
                res.push_back(s.substr(ind,i-ind+1));
                solve(ans,res,s,i+1);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>res;
        solve(ans,res,s,0);
        return ans;
    }
};