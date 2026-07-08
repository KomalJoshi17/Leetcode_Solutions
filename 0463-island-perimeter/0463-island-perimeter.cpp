class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int perimeter=0;

        int dr[]={-1, 1, 0, 0};
        int dc[]={0, 0, -1, 1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];

                        if(nc<0 || nr<0 || nr>=n || nc>=m || grid[nr][nc]==0){
                            perimeter++;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};