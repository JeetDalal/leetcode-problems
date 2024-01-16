class RandomizedSet {
public:
    set<int>s;
    RandomizedSet() {
        //empty
    }
    
    bool insert(int val) {
        if(s.find(val) == s.end()){
            s.insert(val);
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end()){
            return false;
        }else{
            s.erase(val);
            return true;
        }
    }
    
    template<typename S>
auto select_random(const S &s, size_t n) {
  auto it = std::begin(s);
  // 'advance' the iterator n times
  std::advance(it,n);
  return it;
}
    
    int getRandom() {
        auto r = rand() % s.size();
        auto n = *select_random(s, r);
        return n;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */