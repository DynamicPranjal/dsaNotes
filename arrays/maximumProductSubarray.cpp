class Solution {
public:
    int maxProduct(vector<int>& A) {
        int n=A.size();
        int l=1;
        int r=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            l=l*A[i];
            r=r*A[n-i-1];
            ans=max(ans,max(l,r));
            if(l==0)
                l=1;
            if(r==0)
                r=1;
        }
        return ans;
    }
};
