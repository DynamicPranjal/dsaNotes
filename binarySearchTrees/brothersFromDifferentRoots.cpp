class Solution
{
public:

    void inorder(Node *root1,vector<int> &A){
        if(root1==NULL)
            return ;
        inorder(root1->left,A);
        A.push_back(root1->data);
        inorder(root1->right,A);
    }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
        int cnt=0;
        vector<int>A,B;
        inorder(root1,A);
        inorder(root2,B);
        
        unordered_set<int>s(A.begin(),A.end());
        for(int i=0;i<B.size();i++){
            if(s.find(x-B[i])!=s.end())
                cnt++;
        }
        return cnt;
    }
};
