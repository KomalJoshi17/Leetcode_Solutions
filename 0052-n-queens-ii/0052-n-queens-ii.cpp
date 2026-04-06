class Solution {
public:
    int count = 0;

    bool isSafe(int row, int col, vector<int>& queens) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row))
                return false;
        }
        return true;
    }

    void solve(int n, int row, vector<int>& queens) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, queens)) {
                queens[row] = col;
                solve(n, row + 1, queens);
                queens[row] = -1;
            }
        }
    }

    int totalNQueens(int n) {
        vector<int> queens(n, -1);
        solve(n, 0, queens);
        return count;
    }
};