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
    
    TreeNode* f(vector<int>& in, vector<int>& post, int ins, int ine, int posts, int poste){
        if(ins>ine)
            return NULL;
        int rootVal=post[poste];
        TreeNode* root= new TreeNode(rootVal);
        
        int rootInd=ins;
        for(;rootInd<=ine;rootInd++){
            if(in[rootInd]==rootVal)
                break;
        }
        
        int leftsize=rootInd-ins;
        int rightsize=ine-rootInd;
        
        root->left= f(in, post, ins, rootInd-1, posts, posts+leftsize-1);
        root->right= f(in, post, rootInd+1, ine, poste-rightsize, poste-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int s=in.size();
        return f(in, post, 0, s-1, 0, s-1);
    }
};
