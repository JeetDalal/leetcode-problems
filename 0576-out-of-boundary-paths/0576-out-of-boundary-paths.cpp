class Solution { 
public:
    int M=1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(int m,int n,int maxMove,int startRow,int startColumn, int &count){
        if(maxMove<0) return 0;
        if((startRow == -1 || startColumn == -1 || startRow == m || startColumn == n) && (maxMove>=0)){
            count++;
            return 1;
        }
        
        if(dp[startRow][startColumn][maxMove] != -1){
            return dp[startRow][startColumn][maxMove];
        }
        int up = solve(m,n,maxMove-1,startRow+1,startColumn,count);
        int down = solve(m,n,maxMove-1,startRow-1,startColumn,count);
        int right = solve(m,n,maxMove-1,startRow,startColumn+1,count);
        int left = solve(m,n,maxMove-1,startRow,startColumn-1,count);
        
        return dp[startRow][startColumn][maxMove] = ((up+down)%M + (right + left)%M)%M;
        
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int count=0;
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        int val = solve(m,n,maxMove,startRow,startColumn,count);
        return val;
    }
};