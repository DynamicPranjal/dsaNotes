class Solution {
public:
    int jump(vector<int>& A) {
        int cur=0;
        int mx=0;
        int steps=0;
        
        for(int i=0;i<A.size()-1;i++){
            mx=max(mx,i+A[i]);
            if(cur==i){
                cur=mx;
                steps++;
            }
        }
        return steps;
    }
};
