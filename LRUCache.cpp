class LRUCache {
public:
    map<int,int>m;                              //for key value
    map<int,list<int>::iterator> address;       //for storing addresses
    list<int>l;
    int cap,sz;
    LRUCache(int capacity) {
        cap=capacity;
        sz=0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        l.erase(address[key]);
        address.erase(key);
        l.push_front(key);
        address[key]=l.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            l.erase(address[key]);
            address.erase(key);
            m.erase(k+ey);
            sz--;
        }  
        if(sz==cap){
            int k=l.back();
            l.pop_back();
            address.erase(k);
            m.erase(k);
            sz--;
        }
        sz++;
        l.push_front(key);
        address[key]=l.begin();
        m[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
