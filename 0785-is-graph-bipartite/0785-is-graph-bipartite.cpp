class Solution {
public:
    bool bfs(int node,vector<int> &visited,vector<vector<int>> &graph){
        int initialColor=0;
        visited[node] = 0;
        queue<pair<int,int>> q;
        q.push({node,initialColor});
        
        while(!q.empty()){
            int currentNode = q.front().first;
            int currentColor = q.front().second;
            
            q.pop();
            for(auto it: graph[currentNode]){
                if(visited[it]== -1){
                    visited[it] = !currentColor;
                    q.push({it,visited[it]});
                }else{
                    if(currentColor == visited[it]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m = graph[0].size();
        vector<int> visited(n+1,-1);
        
        for(int i=0;i<n;i++){
            if(visited[i]== -1){
                int ans = bfs(i,visited,graph);
                if(!ans) return false;
            }
        }
        return true;
        
    }
};