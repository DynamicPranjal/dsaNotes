// Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
// The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

class Solution {
public:
    
    int func(TreeNode *root,unordered_map<int,int> &m,int &maxcount){
        if(root==NULL)
            return 0;
        int sum=root->val;
        sum+=func(root->left,m,maxcount);
        sum+=func(root->right,m,maxcount);
        m[sum]++;
        if(m[sum]>maxcount)
            maxcount=m[sum];
        
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>m;
        
        if(root==NULL)
            return ans;
        
        int maxcount=0;
        func(root,m,maxcount);
        for(auto x:m){
            if(x.second==maxcount)
                ans.push_back(x.first);
        }
        return ans;
    }
};
