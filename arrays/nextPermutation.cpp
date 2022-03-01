class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n=A.size();
        int i=n-2;
        while(i>=0){
            if(A[i]<A[i+1]){
                break;
            }
            i--;
        }
        
        if(i<0){
            reverse(A.begin(),A.end());
            return ;
        }
        
        for(int j=n-1;j>i;j--){
            if(A[j]>A[i]){
                swap(A[j],A[i]);
                break;
            }
        }
        sort(A.begin()+i+1,A.end());
        return ;
    }
};
