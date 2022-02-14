class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int cnt=0;
        unordered_map<int,int>m;
        m[sum]=1;
        for(auto x:nums){
            sum+=x;
            int y=sum-k;
            if(m.find(y)!=m.end())
                cnt+=m[y];
            m[sum]++;
        }
        return cnt;
    }
};
