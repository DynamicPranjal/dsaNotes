class Solution {
public:
    int search(vector<int>& A, int target) {
        int s=0;
        int n=A.size();
        int e=n-1;
        
        while(s<=e){
            int mid=(e-s)/2+s;
            if(A[mid]==target)
                return mid;
            else if(A[mid]>=A[s]){
                if(target<A[mid] and target>=A[s]){
                    e=mid-1;
                }
                else 
                    s=mid+1;
            }
            else{
                if(target>A[mid] and target<=A[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};
