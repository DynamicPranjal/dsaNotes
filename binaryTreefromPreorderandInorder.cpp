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
    
    TreeNode* func(vector<int>& pre, vector<int>& in, int ins, int ine, int pres, int pree){
        if(ins>ine)
            return NULL;
        
        int rootVal=pre[pres];
        TreeNode* root= new TreeNode(rootVal);
        
        int rootInd=ins;
        for(;rootInd<ine;rootInd++){
            if(in[rootInd]==rootVal){
                break;
            }
        }
        
        int leftsize=rootInd-ins;
        int rightsize=ine-rootInd;
        
        root->left= func(pre, in, ins, rootInd-1, pres+1, pres+leftsize);
        root->right= func(pre, in, rootInd+1, ine, pree-rightsize+1, pree);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s=preorder.size();
        return func(preorder, inorder, 0, s-1, 0, s-1);
    }
};
