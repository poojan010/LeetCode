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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode();
        TreeNode* head = ans;
        dfs(root,head);
        return ans->right;
    }
    
    void dfs(TreeNode* root, TreeNode*& head){
        if(!root) return;
        
        dfs(root->left,head);
        
        head->right = new TreeNode(root->val);
        head = head->right;
        
        dfs(root->right,head);
        
        return;
    }


};