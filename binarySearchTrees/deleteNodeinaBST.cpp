
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        
        if(root->val==key)
            return func(root);
        
        TreeNode *temp=root;
        
        while(root!=NULL){
            if(root->val > key){
                if(root->left!=NULL and root->left->val==key){
                    root->left=func(root->left);
                    break;
                }
                else
                    root=root->left;
            }
            else{
                if(root->right!=NULL and root->right->val==key){
                    root->right=func(root->right);
                    break;
                }
                else
                    root=root->right;
            }
        }
        
        return temp;
    }
    
    TreeNode* func1(TreeNode *root){
        if(root->right==NULL)
            return root;
        return func1(root->right);
    }
    
    TreeNode* func(TreeNode *root){
        if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        
        TreeNode *r=root->right;
        TreeNode *rightest=func1(root->left);
        rightest->right=r;
        return root->left;
    }
    
};
