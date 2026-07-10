class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        int fresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }

        if(fresh==0) return 0;
        vector<int> d = {0,1,0,-1,0};
        int min=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [x,y]=q.front();
                q.pop();
                for(int z=0;z<4;z++){
                    int ni=x+d[z];
                    int nj=y+d[z+1];

                    if(ni>=0 && nj>=0 && ni<n && nj<m){
                        if(grid[ni][nj]==1){
                            grid[ni][nj]=2;
                            fresh--;
                            q.push({ni,nj});
                        }
                    }
                }
            }
            min++;
        }

        if(fresh!=0) return -1;

        return min-1;
    }
};