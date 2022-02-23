class Solution
{
	public:
	    vector<string>ans;
	    void func(int i,string &s){
	        if(i==s.size()-1){
	            ans.push_back(s);
	            return ;
	        }
	        for(int j=i;j<s.size();j++){
	            swap(s[j],s[i]);
	            func(i+1,s);
	            swap(s[j],s[i]);
	        }
	    }
	    
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    func(0,s);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
