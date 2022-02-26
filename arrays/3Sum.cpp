class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        sort(A.begin(),A.end());
        vector<vector<int>>ans;
        int n=A.size();
        for(auto x:A)
            cout<<x<<" ";
        cout<<endl;
        for(int i=0;i<n-2;i++){
            if(i==0 or (i>0 and A[i]!=A[i-1])){
                int l=i+1;
                int r=n-1;
                
                int sum=0;
                sum=-A[i];
                while(l<r){
                    if(A[l]+A[r]==sum){
                        vector<int>temp;
                        temp.push_back(A[l]);
                        temp.push_back(A[r]);
                        temp.push_back(-sum);
                        ans.push_back(temp);
                        while(l<r and A[l]==A[l+1])
                            l++;
                        while(l<r and A[r]==A[r-1])
                            r--;
                        l++;
                        r--;
                    }
                    else if(A[l]+A[r]<sum){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
