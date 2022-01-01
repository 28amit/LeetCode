/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<TreeNode*>>mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(mp.find(n)==mp.end()){
            vector<TreeNode*> ans;
            if(n==1)
                ans.push_back(new TreeNode(0));
            else if(n%2){
                for(int i=0;i<n;i++){
                    vector<TreeNode*> l=allPossibleFBT(i);
                    vector<TreeNode*> r=allPossibleFBT(n-1-i);
                    for(auto x:l){
                        for(auto y:r){
                            ans.push_back(new TreeNode(0,x,y));
                        }
                    }
                }
            }
            mp[n]=ans;
        }
        return mp[n];     
    }
};