class Solution {
public:
    int solve(int n, vector<int> &v){
        
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
        if(n < 3){
            return 1;
        }
        
        vector<int> v(n+1, -1);  
        v[0] = 0;
        v[1] = v[2] = 1;
        int result = solve(n, v);
        return result;
    }
};
