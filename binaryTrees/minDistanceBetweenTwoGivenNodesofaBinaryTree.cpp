class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    Node* func(Node *root,int a,int b){
        if(root==NULL)
            return NULL;
        if(root->data==a or root->data==b)
            return root;
            
        Node *left=func(root->left,a,b);
        Node *right=func(root->right,a,b);
        
        if(left!=NULL and right!=NULL)
            return root;
        else if(left!=NULL)
            return left;
        else 
            return right;
    }
    
    int fun(Node *root,int x,int d){
        if(root==NULL)
            return INT_MAX;
        
        if(root->data==x)
            return d;
        int p=fun(root->left,x,d+1);
        int q=fun(root->right,x,d+1);
        return min(p,q);
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node *lca=func(root,a,b);
        int p=fun(lca,a,0);
        int q=fun(lca,b,0);
        return p+q;
    }
};
