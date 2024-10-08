class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for(int i = 0;i < nums.size();i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > k1){
            pq.pop();
        }
        return pq.top();
    }
};