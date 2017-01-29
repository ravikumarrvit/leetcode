class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = (m) ? board[0].size() : 0;
        int neighbor_count;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                neighbor_count = -board[i][j];
                for (int k = max(i - 1, 0); k <= min(i + 1, m - 1); k++)
                    for (int l = max(j - 1, 0); l <= min(j + 1, n - 1); l++)
                        neighbor_count += (board[k][l] & 1);
                // 1. DEAD_CELL with exactly 3 neighbors or
                // 2. LIVE_CELL with 2 nighbors
                // In all other cases, the cell would become DEAD_CELL in the next state
                
                if ((neighbor_count | board[i][j]) == 3)
                    board[i][j] |= 2;
            }
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] >>= 1;
    }
};