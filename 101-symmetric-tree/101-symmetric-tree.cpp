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
    bool solve(TreeNode* l1, TreeNode* l2){
        if(!l1&&!l2)
            return 1;
        if(!l1||!l2)
            return 0;
        return (l1->val==l2->val)&&solve(l1->left,l2->right)&&solve(l2->left,l1->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return 1;
        return solve(root->left,root->right);
    }
};