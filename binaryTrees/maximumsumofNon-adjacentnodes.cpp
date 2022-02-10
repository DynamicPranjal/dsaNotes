class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*, int> umap;
    int getMaxSum(Node* root)
    {
        // base case
        if (!root)
            return 0;
 
        // if the max sum from the  node is already in
        // map,return the value
        if (umap[root])
            return umap[root];
 
        // if the current node(root) is included in result
        // then find maximum sum
        int inc = root->data;
 
        // if left of node exists, add their grandchildren
        if (root->left) {
            inc += getMaxSum(root->left->left)
               + getMaxSum(root->left->right);
        }
        // if right of node exist,add their grandchildren
        if (root->right) {
            inc += getMaxSum(root->right->left)
                   + getMaxSum(root->right->right);
        }
 
        // if the current node(root) is excluded, find the
        // maximum sum
        int ex = getMaxSum(root->left) + getMaxSum(root->right);
 
        // store the maximum of including & excluding the node
        // in map
        umap[root] = max(inc, ex);
        return max(inc, ex);
    }
};
