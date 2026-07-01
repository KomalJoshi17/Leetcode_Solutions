class Solution {
public:
    bool safe(vector<vector<char>>& board, int r, int c, char ch){
        // Row
        for(int i = 0; i < 9; i++){
            if(board[r][i] == ch)
                return false;
        }

        // Column
        for(int i = 0; i < 9; i++){
            if(board[i][c] == ch)
                return false;
        }

        // 3x3 Grid
        int sr = (r / 3) * 3;
        int sc = (c / 3) * 3;

        for(int i = sr; i < sr + 3; i++){
            for(int j = sc; j < sc + 3; j++){
                if(board[i][j] == ch)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int r, int c){
        // Entire board completed
        if(r == 9)
            return true;

        // Move to next row
        if(c == 9)
            return solve(board, r + 1, 0);

        // Already filled
        if(board[r][c] != '.'){
            return solve(board, r, c + 1);
        }

        // Try digits 1 to 9
        for(char ch = '1'; ch <= '9'; ch++){

            if(safe(board, r, c, ch)){

                board[r][c] = ch;

                if(solve(board, r, c + 1))
                    return true;

                // Backtrack
                board[r][c] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};