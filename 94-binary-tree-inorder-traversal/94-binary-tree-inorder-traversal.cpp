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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int>ans;
        stack<TreeNode*>s;
        TreeNode* curr=root;
        while(curr||!s.empty()){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            TreeNode * tmp=s.top();
            s.pop();
            ans.push_back(tmp->val);
            curr=tmp->right;
        }
        return ans;
    }
};