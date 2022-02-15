class Solution
{
    public:
    
    int ans;
        
    void func(Node *root,int &cnt,int K){
        if(root==NULL)
            return ;
        func(root->right,cnt,K);
        cnt++;
        if(cnt==K){
            ans=root->data;
            return ;
        }
        func(root->left,cnt,K);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int cnt=0;
        func(root,cnt,K);
        return ans;
    }
};
