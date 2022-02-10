class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node *cur=NULL,*prev=NULL;
    Node *bToDLL(Node *root)                // inorder traversal
    {
        // your code here
        if(root==NULL)
            return NULL;
        bToDLL(root->left);
        
        if(prev==NULL)
            cur=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        bToDLL(root->right);
        return cur;
    }
};
