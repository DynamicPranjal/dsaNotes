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
    
    array<int,3> func(TreeNode *root, int &ans){
        if(!root)
            return {0,INT_MAX,INT_MIN};
        
        array<int,3> left;
        array<int,3> right;
        left=func(root->left,ans);
        right=func(root->right,ans);
        
        if(root->val>left[2] and root->val<right[1]){
            int temp=root->val+left[0]+right[0];
            ans=max(ans,temp);
            return {temp,min(root->val,left[1]),max(root->val,right[2])};
        }
        
        return {0,INT_MIN,INT_MAX};
    }
    
    int maxSumBST(TreeNode* root) {
        int ans=0;
        func(root,ans);
        return ans;
    }
};
