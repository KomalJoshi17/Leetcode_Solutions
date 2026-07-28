class Solution {
public:
    int m, n;
    int t[71][71][71];

    int solve(vector<vector<int>>& grid, int row, int col1, int col2) {
        if (row < 0 || row >= m || col1 < 0 || col1 >= n || col2 < 0 ||
            col2 >= n)
            return 0;

        if (t[row][col1][col2] != -1)
            return t[row][col1][col2];

        int cherry = grid[row][col1];
        if (col1 != col2)
            cherry += grid[row][col2];

        int ans = 0;
        for (int val1 = -1; val1 <= 1; val1++) {
            for (int val2 = -1; val2 <= 1; val2++) {
                int new_row = row + 1;
                int new_col1 = col1 + val1;
                int new_col2 = col2 + val2;

                ans = max(ans, solve(grid, new_row, new_col1, new_col2));
            }
        }
        return t[row][col1][col2] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(grid, 0, 0, n - 1);
    }
};