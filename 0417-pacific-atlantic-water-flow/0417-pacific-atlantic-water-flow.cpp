class Solution {
public:
    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        int m=heights.size();
        int n=heights[0].size();
        visited[i][j]=true;
        
        for(auto& d:dir){
            int ni=i+d[0];
            int nj=j+d[1];

            if(ni<0 || ni>=m || nj<0 || nj>=n){
                continue;
            } 

            if(visited[ni][nj]){
                continue;
            }

            if(heights[ni][nj] < heights[i][j]){
                continue;
            }
            
            dfs(ni,nj,heights,visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int j=0;j<n;j++){
            dfs(0,j,heights,pacific);
        }  

        for(int i=0;i<m;i++){
            dfs(i,0,heights,pacific);
        }

        for(int j=0;j<n;j++){
            dfs(m-1,j,heights,atlantic);
        }

        for(int i=0;i<m;i++){
            dfs(i,n-1,heights,atlantic);
        }

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};