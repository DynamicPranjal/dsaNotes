class Solution {
public:
    
    void func(TreeNode *root,int &sum){
        
        if((root->val)%2==0){
            if(root->left!=NULL){
                if(root->left->left!=NULL)
                    sum+=root->left->left->val;
                if(root->left->right!=NULL)
                    sum+=root->left->right->val;
            }
            if(root->right!=NULL){
                if(root->right->left!=NULL)
                    sum+=root->right->left->val;
                if(root->right->right!=NULL)
                    sum+=root->right->right->val;
            }
        }
        if(root->left)
            func(root->left,sum);
        if(root->right)
            func(root->right,sum);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
            return 0;
        int sum=0;
        func(root,sum);
        return sum;
    }
};
