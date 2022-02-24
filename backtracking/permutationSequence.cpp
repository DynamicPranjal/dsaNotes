class Solution {
public:
    string getPermutation(int N, int k) {
        k--;
        vector<int>A;
        for(int i=1;i<=N;i++)
            A.push_back(i);
        
        int fact[N+1];
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=N;i++){
            fact[i]=i*fact[i-1];
        }
        int n=N;
        string ans;
        int no;
        while(n>0){
            no=k/fact[n-1];
            k=k%fact[n-1];
            ans+=A[no]+'0';
            A.erase(A.begin()+no);
            n--;
        }
        return ans;
    }
};
