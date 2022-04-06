class Solution {
public:
    //O(n+m) : KMP algorithm :)
    vector<int> func(string s){
        int n=s.size();
        int len=0;
        vector<int>lps(n,0);
        
        for(int i=1;i<n;){
            if(s[len]==s[i]) lps[i++]=++len;
            else if(len) len=lps[len-1];
            else  lps[i++]=0;
        }
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        vector<int>A=func(needle);
        
        int i=0,j=0;
        int n=haystack.size();
        int m=needle.size();
        
        int ans=0;
        while(i<n and j<m){
            if(haystack[i]==needle[j]) i++,j++;
            else if(j==0) i+=1;
            else j=A[j-1];
        }
        if(j==m)
            return i-needle.size();
        return -1;
    }
};
