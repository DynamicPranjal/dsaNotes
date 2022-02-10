class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>m;
        unordered_map<TreeNode*,bool>vis;
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                m[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                m[temp->right]=temp;
            }
        }
        
        q.push(target);
        vis[target]=1;
        int i=0;
        
        while(!q.empty()){
            int size=q.size();
            if(i==k)
                break;
            i++;
            
            for(int i=0;i<size;i++){
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left and vis[temp->left]!=1){
                    q.push(temp->left);
                    vis[temp->left]=1;
                }
                if(temp->right and vis[temp->right]!=1){
                    q.push(temp->right);
                    vis[temp->right]=1;
                }
                if(m[temp] and vis[m[temp]]!=1){
                    q.push(m[temp]);
                    vis[m[temp]]=1;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
