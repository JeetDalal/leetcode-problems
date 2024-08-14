class Solution {
public:
      int dp[50];

    Solution() {
        // Initialize all dp elements to -1
        for(int i = 0; i < 50; i++) {
            dp[i] = -1;
        }
    }
    int solve(int n){
        if(n<=0) return dp[0];
        if(n==1) return dp[1];
        if(n==2) return dp[2];
        if(dp[n]!= -1) return dp[n];
        
        return dp[n] = solve(n-1) + solve(n-2);
    }
    int climbStairs(int n) {
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        int ans = solve(n);
        return ans;
    }
};