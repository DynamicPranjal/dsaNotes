bool func(Node *root,int mn,int mx){
    if(root==NULL)
        return false;
    if(mn==mx)
        return true;
        
    int a=func(root->left,mn,root->data-1);
    int b=func(root->right,root->data+1,mx);
    return a or b;
}

bool isDeadEnd(Node *root)
{
    //Your code here
    bool ans=func(root,1,INT_MAX);
    return ans;
    
}
