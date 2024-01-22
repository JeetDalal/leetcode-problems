class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        vector<int> ans;
        set<int> s;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            s.insert(v[i]);
            if(v[i] == v[i+1]){
                ans.push_back(v[i]);
            }
        }
        s.insert(v[v.size()-1]);
        int i=1;
        for(auto &val:s){
            cout<<val<<" ";
            if(val != i){
                ans.push_back(i);
                break;
            }
            i++;
        }
        if(ans.size() == 1){
            ans.push_back(v.size());
        }
        
        return ans;
    }
};