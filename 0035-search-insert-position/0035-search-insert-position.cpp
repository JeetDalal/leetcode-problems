class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        for(int i=0;i<v.size();i++){
            if(v[i]>=target){
                return i;
            }
            
        }
        return v.size();
    }
};