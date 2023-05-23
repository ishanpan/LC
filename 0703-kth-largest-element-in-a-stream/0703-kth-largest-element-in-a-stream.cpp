class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int maxK = 0;
    KthLargest(int k, vector<int>& nums) {
        for(auto x:nums){
            pq.push(x);
           
        }
        maxK=k;
        while(pq.size()>maxK){
            pq.pop();
        }

    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>maxK){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */