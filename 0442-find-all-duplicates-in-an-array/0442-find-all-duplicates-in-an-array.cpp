class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> v;
        for(auto &val: nums){
            m[val]++;
        }
        for(auto &val: m){
            if(val.second > 1){
                v.push_back(val.first);
            }
        }
        return v;
    }
};