class Solution {
public:
    
    bool pal(int i, int j, string s){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    
    void func(vector<vector<string>> &ans, vector<string> temp, int i, string s){
        if(i==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<s.size();j++){
            if(pal(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                func(ans,temp,j+1,s);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n=s.size();
        func(ans,temp,0,s);
        return ans;
    }
};
