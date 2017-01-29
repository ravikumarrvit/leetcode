class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows, cols, temp;
        
        if (matrix.size() == 0)
            return;
            
        rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        
        for (int start_row = 0, start_col = 0; start_row <= rows/2 && start_col <= cols/2; start_row++, start_col++) {
            for (int row = start_row, col = start_col; row < rows - start_row && col < cols - start_col; row++, col++) {
                temp = matrix[start_row][col];
                matrix[start_row][col] = matrix[rows - row][start_col];
                matrix[rows - row][start_col] = matrix[rows - start_row][cols - col];
                matrix[rows - start_row][cols - col] = matrix[row][cols - start_col];
                matrix[row][cols - start_col] = temp;
            }
        }
    }
};