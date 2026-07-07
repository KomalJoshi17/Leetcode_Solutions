class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int ov = image[sr][sc];

        if (ov == color)
            return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto [dx, dy] : dir) {
                int ni = i + dx;
                int nj = j + dy;

                if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                    image[ni][nj] == ov) {

                    image[ni][nj] = color;
                    q.push({ni, nj});
                }
            }
        }

        return image;
    }
};