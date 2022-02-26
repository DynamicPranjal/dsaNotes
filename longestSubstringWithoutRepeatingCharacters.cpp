class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int n=s.size();
        int start=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end() and m[s[i]]>=start){
                start=m[s[i]]+1;
            }
            m[s[i]]=i;
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};
