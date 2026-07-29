class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        
        vector<int> cols(n, 0);          // track columns
        vector<int> diag1(2*n - 1, 0);   // track main diagonals (r - c)
        vector<int> diag2(2*n - 1, 0);   // track anti-diagonals (r + c)
        
        backtrack(0, n, board, res, cols, diag1, diag2);
        return res;
    }
    
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& res,
                   vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;
            
            // place queen
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;
            
            backtrack(row + 1, n, board, res, cols, diag1, diag2);
            
            // remove queen (backtrack)
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }
};
