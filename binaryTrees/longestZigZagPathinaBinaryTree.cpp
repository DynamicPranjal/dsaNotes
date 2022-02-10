class Solution {
public:
    int ans=0;
    
    void func(TreeNode *root,int cnt,int dir){
        
        if(root==NULL)
            return ;
        ans=max(ans,cnt);
        if(dir){
            func(root->right,cnt+1,0);
            func(root->left,1,1);
        }
        else{
            func(root->left,cnt+1,1);
            func(root->right,1,0);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        func(root,0,1);
        func(root,0,0);
        
        return ans;
    }
};
