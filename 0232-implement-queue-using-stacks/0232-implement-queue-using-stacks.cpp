class MyQueue {
public:
    vector<int> v;
    MyQueue() {
       
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    int pop() {
        int val = v[0];
        reverse(v.begin(),v.end());
        v.pop_back();
        reverse(v.begin(),v.end());
        return val;
    }
    
    int peek() {
        return v[0];
    }
    
    bool empty() {
        return (v.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */