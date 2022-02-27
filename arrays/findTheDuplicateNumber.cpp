class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int f=A[0];
        int s=A[0];
        
        do{
            f=A[A[f]];
            s=A[s];
        }while(f!=s);
        
        f=A[0];
        while(f!=s){
            f=A[f];
            s=A[s];
        }
        
        return s;
    }
};
