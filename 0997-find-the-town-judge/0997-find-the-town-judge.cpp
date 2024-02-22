class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,pair<int,int>> m;
                       if(trust.size() == 0 && n==1){
                                           return n;
                 }else if(trust.size() == 0 && n!=1){
                                     return -1;
                            }
             for(int i=0;i<trust.size();i++){
    m[trust[i][1]].first++;
            m[trust[i][0]].second++;
        }
                         for(auto &val:m){
            if(val.second.first == n-1 && val.second.second == 0) return val.first;
             }
                 return -1;
    }
};