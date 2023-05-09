class Solution {
public:
    int bfs(int src,int dst,int n,set<int> adj[]){
        vector<int> visited(n);
        visited[src]=1;
        queue<pair<int,int>> q;
        q.push({src,0});

        while(!q.empty()){
            int node=q.front().first;
            int distance=q.front().second;
            q.pop();

            if(node==dst)
                return distance;

            for(auto adjacent:adj[node]){
                if(!visited[adjacent]){
                    q.push({adjacent,distance+1});
                    visited[adjacent]=1;
                }
            }
        }

        return INT_MAX;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int ans=INT_MAX;
        set<int> adj[n];
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].insert(v);
            adj[v].insert(u);
        }
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].erase(v);
            adj[v].erase(u);

            ans=min(ans,bfs(u,v,n,adj));
        }
        if(ans==INT_MAX) return -1;
        return ans+1;
    }
};

/* 
Thought proccess to be followed here is that for each edge that is the part of a cycle we can simply remove that edge and find the shortest distance between its
nodes and find the shortest distance between them using either bfs or dfs
Pseudo Code : 
for each edge in edges :
    u=edge[0]
    v=edge[1]
    remove edge from the graph
    distance=shortedDistanceBewtween(u,v)
    result = min(result,distance)
return this result
*/
