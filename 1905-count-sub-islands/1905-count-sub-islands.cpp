class Solution {
public:
    bool dfs(int i,int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int n=grid1.size(); 
        int m=grid1[0].size();

        if(i<0 || j<0 || i>=n || j>=m || grid2[i][j]==0){
            return true;
        }
        grid2[i][j]=0;

        bool isSubIsland = (grid1[i][j] == 1);

        bool a=dfs(i+1,j,grid1,grid2);
        bool b=dfs(i-1,j,grid1,grid2);
        bool c=dfs(i,j+1,grid1,grid2);
        bool d=dfs(i,j-1,grid1,grid2);

        return isSubIsland && a && b && c && d;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(); 
        int m=grid1[0].size();

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    if(dfs(i,j,grid1,grid2)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};