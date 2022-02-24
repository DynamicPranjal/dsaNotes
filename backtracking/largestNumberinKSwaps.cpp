class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans;
    
    void func(int i,string s,int k){
        if(k==0)
            return ;
            
        char mx=s[i];
        for(int j=i+1;j<s.size();j++){
            if(s[j]>mx)
                mx=s[j];
        }
        
        if(mx!=s[i])
            k--;
        
        for(int j=s.size()-1;j>=i;j--){
            if(mx==s[j]){
                swap(s[j],s[i]);
                if(s.compare(ans)>0)
                    ans=s;
                func(i+1,s,k);
                swap(s[j],s[i]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       ans=str;
       func(0,str,k);
       return ans;
    }
};
