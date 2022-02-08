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
    TreeNode* lastRight(TreeNode* link){
        if(!link->right)
            return link;
        return lastRight(link->right);
    }
    TreeNode* solve(TreeNode* node){
        if(!node->left)
            return node->right;
        if(!node->right)
            return node->left;
        TreeNode *tmp=node->right;
        TreeNode *last=lastRight(node->left);
        last->right=tmp;
        return node->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val==key)
            return solve(root);
        TreeNode *curr=root;
        while(curr){
            if(curr->val>key){
                if(curr->left&&curr->left->val==key){
                    curr->left=solve(curr->left);
                    break;
                }
                else
                    curr=curr->left;
            }
            else{
                if(curr->right&&curr->right->val==key){
                    curr->right=solve(curr->right);
                    break;
                }
                else
                    curr=curr->right;
            }
        }
        return root;
    }
};