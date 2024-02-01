class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            vector<int> mini;
            mini.push_back(nums[i]);
            if(abs(nums[i]-nums[i+2])<=k){
                mini.push_back(nums[i+1]);
                mini.push_back(nums[i+2]);
            }else{
                return {};
            }
            v.push_back(mini);
        }
        return v;
    }
};