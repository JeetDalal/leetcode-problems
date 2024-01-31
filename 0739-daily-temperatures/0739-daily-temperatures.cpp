class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<pair<int,int>> s;
        vector<int> res;
        for(int i=v.size()-1;i>=0;i--){
            while(!s.empty() && s.top().second <= v[i]){
                //pop...
                s.pop();
            }
            if(s.empty()){
                res.push_back(0);
            }else{
                res.push_back(-i + s.top().first );
            }
            s.push({i,v[i]});
        }
        reverse(res.begin(),res.end());
        return res;
    }
};