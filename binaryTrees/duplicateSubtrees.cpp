vector<Node*>ans;
unordered_map<string,int>m;

string postorder(Node *node){                   // following postorder traversal as s1 and s2 are precalculated  
    if(node==NULL)                              // string left precal + middle digit + string right precal
        return "!";
    string s1=postorder(node->left);
    string s2=postorder(node->right);
    
    string s="";
    s=s1+to_string(node->data)+s2;
    m[s]++;
    if(m[s]==2)
        ans.push_back(node);
    return s;
}

vector<Node*> printAllDups(Node* root)
{
    // Code here
    m.clear();
    ans.clear();
    postorder(root);
    return ans;
}
