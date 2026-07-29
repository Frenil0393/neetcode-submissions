class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> cols(n, 0);          // track columns
        vector<int> diag1(2*n - 1, 0);   // track main diagonals (r - c)
        vector<int> diag2(2*n - 1, 0);   // track anti-diagonals (r + c)
        
        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }
    
    void backtrack(int row, int n, vector<int>& cols, vector<int>& diag1, vector<int>& diag2, int& count) {
        if (row == n) {
            count++;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;
            
            // place queen
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;
            
            backtrack(row + 1, n, cols, diag1, diag2, count);
            
            // remove queen (backtrack)
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }
};
