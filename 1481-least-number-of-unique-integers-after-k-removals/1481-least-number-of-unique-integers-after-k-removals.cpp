class Solution {
public:
    static bool fcompare(pair<int, pair<int, int> > p,
              pair<int, pair<int, int> > p1)
{
    if (p.second.second != p1.second.second)
        return (p.second.second > p1.second.second);
    else
        return (p.second.first < p1.second.first);
}
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, pair<int, int> > hash; 
       
    for (int i = 0; i < arr.size(); i++) {
        if (hash.find(arr[i]) != hash.end())
            hash[arr[i]].second++;
        else{
            hash[arr[i]] = make_pair(i, 1);
          
        }
            
    } 
    
    vector<pair<int, pair<int, int> > > b;
    for (auto &it:hash)
        b.push_back(make_pair(it.first, it.second));
 
    sort(b.begin(), b.end(), fcompare);
    while(k>0){
        int val = b[b.size()-1].first;
        cout<<val<<" ";  
        if(hash.find(val) != hash.end()){
            if(hash[val].second == 1){
                b.pop_back();
                hash.erase(val);
            }else{
                hash[val].second--;
            }
        }
        k--;
    }
     return b.size();  
    }
};