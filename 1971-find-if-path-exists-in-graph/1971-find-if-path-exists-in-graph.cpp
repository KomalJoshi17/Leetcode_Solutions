class Solution {
public:
    void dfs(int source, vector<vector<int>>&adj, vector<int>&vis){
        vis[source]=1;

        for(int e:adj[source]){
            if(!vis[e]){
                dfs(e,adj,vis);
            }
        }    
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);
        dfs(source,adj,vis);

        return vis[destination];
    }
};