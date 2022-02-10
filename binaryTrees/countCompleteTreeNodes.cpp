class Solution {
public:
    
    int func(TreeNode *root){
        if(root==NULL)
            return 0;
        int ans=0;
        if(root->left!=NULL)
            ans+=func(root->left)+1;
        if(root->right!=NULL)
            ans+=func(root->right)+1;
        return ans;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=func(root)+1;
        return ans;
    }
};
