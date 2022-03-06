
class Solution {
public:
    
    int func(TreeNode *root,int &res){
        if(root==NULL)
            return 0;
        int l=func(root->left,res);
        int r=func(root->right,res);
        
        int temp=max({max(l,r)+root->val,root->val});
        int ans=max(temp,l+r+root->val);
        res=max(res,ans);
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int res=-1e7;
        func(root,res);
        return res;
    }
};
