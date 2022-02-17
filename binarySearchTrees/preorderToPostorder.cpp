Node *makeTree(Node *root,int x){
    if(root==NULL)
        return newNode(x);
    if(x<root->data)
        root->left=makeTree(root->left,x);
    else
        root->right=makeTree(root->right,x);
}

Node* post_order(int pre[], int size)
{
    //code here
    Node *root=NULL;
    for(int i=0;i<size;i++){
        root=makeTree(root,pre[i]);
    }
    return root;
}
