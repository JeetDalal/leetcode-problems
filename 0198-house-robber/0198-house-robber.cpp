class Solution {
public:
    int solve(int index,vector<int> &v,vector<int> &dp){
        if(index==0)
            return v[index];
        if(index<0)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int left = v[index]+solve(index-2,v,dp);
        int right = solve(index-1,v,dp);
        return dp[index]=max(left,right);
    }
    int rob(vector<int>& v) {
        vector<int> dp(v.size(),-1);
        int x=solve(v.size()-1,v,dp);
        return x;
    }
};