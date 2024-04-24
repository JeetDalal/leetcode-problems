class Solution {
public:
    int solve(int n, vector<int>& v){
        if(n == 0){
            return 0;
        }
        if(n < 3){
            return 1;
        }
        if(v[n] != -1){
            return v[n];
        }
        
        v[n] = solve(n-3, v) + solve(n-1, v) + solve(n-2, v);
        return v[n];
    }
    
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        
        vector<int> v(max(n + 1, 3), -1);  // Ensure vector size is at least max(n+1, 3)
        v[0] = 0;
        v[1] = v[2] = 1;
        int result = solve(n, v);
        return result;
    }
};
