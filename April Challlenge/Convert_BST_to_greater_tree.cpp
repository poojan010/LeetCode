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
    int curr = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
    
    /*
        In order Traversal technique
        go right
        update root
        go left
    */
    void dfs(TreeNode* root){
        if(!root) return;
        
        if(root->right) dfs(root->right);
        
        curr += root->val;
        root->val = curr;
        
        if(root->left) dfs(root->left);
        
        return;
    }

};