class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winner;
        unordered_map<int,int> loser;
        vector<vector<int>> v;
        for(int i=0;i<matches.size();i++){
            winner[matches[i][0]]++;
            loser[matches[i][1]]++;
        }
        vector<int> v1,v2;
        for(auto &val:winner){
            if(loser.find(val.first) == loser.end()){
                v1.push_back(val.first);
            }
        }
        for(auto &val:loser){
            if(val.second == 1){
                v2.push_back(val.first);
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        v.push_back(v1);
        v.push_back(v2);
        return v;
    }
};