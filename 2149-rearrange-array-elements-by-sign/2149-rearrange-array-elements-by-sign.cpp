class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v;
        int i=0,j=0;
        while(i<nums.size() && j<nums.size()){
            while(nums[i]<0 && i<nums.size()){
                i++;
            }
            v.push_back(nums[i]);
            while(nums[j]>0 && j<nums.size()){
                j++;
            }
            v.push_back(nums[j]);
            i++;
            j++;
        }
        return v;
    }
};