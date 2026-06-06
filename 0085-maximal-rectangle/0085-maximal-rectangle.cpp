class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;        
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int result = 0;
        vector<int> histogram(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == '1') {
                    histogram[j] += 1;
                } else {
                    histogram[j] = 0;
                }
            }
            result = max(result, largestRectangleArea(histogram));
        }
        return result;
    }
};