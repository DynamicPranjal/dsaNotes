class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int ans=0;
    void inorder(Node *root,int &cnt,int K){
        if(root==NULL)
            return ;
        inorder(root->left,cnt,K);
        cnt++;
        if(cnt==K){
            ans=root->data;
            return ;
        }
        inorder(root->right,cnt,K);
    }
    
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        int cnt=0;
        inorder(root,cnt,K);
        return (ans!=0) ? ans : -1;
    }
};
