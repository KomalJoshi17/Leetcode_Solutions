class Solution {
public:
    bool dfs(int course,vector<vector<int>>&adj,vector<int>&visited) {
        if(visited[course]==1) return false;
        if(visited[course]==2) return true;
        visited[course]=1;

        for(int next:adj[course]) {
            if (!dfs(next,adj,visited)) return false;
        }
        visited[course]=2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &e:prerequisites) {
            int a=e[0];
            int b=e[1];
            adj[b].push_back(a);
        }

        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,adj,visited)){
                return false;
            } 
        }

        return true;
    }
};