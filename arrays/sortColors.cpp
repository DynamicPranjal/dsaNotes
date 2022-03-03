class Solution {
public:
    void sortColors(vector<int>& A) {
        int n=A.size();
        int l=0,m=0,r=n-1;
        while(m<=r){
            if(A[m]==0){
                swap(A[m],A[l]);
                l++;
                m++;
            }
            else if(A[m]==1){
                m++;
            }
            else{
                swap(A[r],A[m]);
                r--;
            }
        }
    }
};
