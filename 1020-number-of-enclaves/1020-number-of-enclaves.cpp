class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<int> delX={-1,0,1,0};
        vector<int> delY={0,1,0,-1};
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && (i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1){
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        
        //BFS on all boundary 1's
        while(!q.empty()){
            int row = q.front().first;
            int column = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nR = row+delX[i];
                int nC = column+delY[i];
                
                if(nR>=0 && nR<n && nC>=0 && nC<m){
                    if(!visited[nR][nC] && grid[nR][nC]==1){
                        visited[nR][nC]=1;
                        q.push({nR,nC});
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};