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
    // O(N*H)
    int getans(TreeNode *root){
        if(!root) return 0;
        int l=getans(root->left);
        int r=getans(root->right);
        return max(l,r)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int h=getans(root->left)+getans(root->right);
        int leftans=diameterOfBinaryTree(root->left);
        int rightans=diameterOfBinaryTree(root->right);
        return max({h, leftans, rightans});
    }
};
