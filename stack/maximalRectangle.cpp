class Solution {
public:
    
    int func(vector<int> &v, int m){
        stack<int>s;
        
        int ans=0;
        for(int i=0;i<=m;i++){
            while(!s.empty() and (i==m or v[s.top()]>=v[i])){
                int height=v[s.top()];
                int width;
                s.pop();
                
                
                if(s.empty())
                    width=i;
                else
                    width=i-s.top()-1;
                
                // cout<<i<<" "<<height<<endl;
                
                ans=max(ans,width*height);
            }
            s.push(i);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>A(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++)
            A[0][i]=(matrix[0][i]=='1')?1:0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                A[i][j]=(matrix[i][j]=='1')? A[i-1][j]+1:0;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            vector<int>v(m);
            for(int j=0;j<m;j++)
                v[j]=A[i][j];
            
            int temp=func(v,m);
            ans=max(ans,temp);
        }
        return ans;
    }
};
