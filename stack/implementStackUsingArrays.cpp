class CustomStack {
public:
    int max;
    vector<int> a;
    CustomStack(int maxSize) {
        max=maxSize;
    }
    
    void push(int x) {
        if(a.size()<max)
            a.push_back(x);
    }
    
    int pop() {
        if(a.size()!=0){
            int x;
            x=a.back();
            a.pop_back();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(a.size()<k)
            k=a.size();
        for(int i=0;i<k;i++)
            a[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
