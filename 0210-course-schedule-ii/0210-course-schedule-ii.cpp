class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[v].push_back(u);
        }
        
        vector<int>inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto node:adj[i]){
                inDegree[node]++;
            }
        }
        
        vector<int>ans;
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto neigh:adj[node]){
                inDegree[neigh]--;
                
                if(inDegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        
        if(ans.size()!=V) return {};
        
        return ans;
    }
};