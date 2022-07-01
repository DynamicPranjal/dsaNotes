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
    //O(H)
    int func(TreeNode* root, int &diameter){
        if(!root) return 0;
        int left=func(root->left, diameter);
        int right=func(root->right, diameter);
        diameter=max(diameter, left+right);
        return max(left,right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=INT_MIN;
        func(root, diameter);
        return diameter;
    }
};
