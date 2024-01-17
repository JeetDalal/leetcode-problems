class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++; 
        }
        arr.clear();
        for(auto &val:m){
            arr.push_back(val.second);
        }
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i] == arr[j]){
                    return false;
                }
            }
        }
        return true;
        
    }
};