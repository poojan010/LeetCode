
/*
    if val < low then left subtree have all values that are < low 
    so discard left subtree
    if val > high then right subtree will have all values that are > high
    so discard right subtree
    now answer is root
    before that call trimBST(root->left) and trimBST(root->right)
*/
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(root == NULL) return NULL;
        
        if(root->val < low) return trimBST(root->right,low,high);
        else if (root->val > high) return trimBST(root->left,low,high);
        
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        
        return root;
    }

};

