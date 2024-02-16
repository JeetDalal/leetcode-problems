class Solution {
public:
    static bool compare(int &a,int &b){
        return a>b;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        vector<int> f;
        for(auto &val:arr){
            m[val]++;
        }
        for(auto &val:m){
            f.push_back(val.second);
        }
        // cout<<f.size();
        sort(f.begin(),f.end(),compare);
        while(k>0){
            if(f[f.size()-1]==1){
                cout<<f[f.size()-1]<<" ";
                f.pop_back();
            }else{
                f[f.size()-1]--;
            }
            k--;
        }
        return f.size();
        
    }
};