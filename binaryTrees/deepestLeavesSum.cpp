class Solution {
public:
    
    int func(TreeNode *root){
        if(root==NULL)
            return 0;
        
        int x=0,y=0;
        if(root->left!=NULL)
            x=func(root->left)+1;
        if(root->right!=NULL)
            y=func(root->right)+1;
        
        return max(x,y);
    }
    
    int func1(TreeNode *root,int cur,int mxh){
        if(root==NULL)
            return 0;
        if(cur==mxh)
            return root->val;
        
        return func1(root->left,cur+1,mxh) + func1(root->right,cur+1,mxh);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int mh=func(root);
        
        return func1(root,0,mh);
    }
};
