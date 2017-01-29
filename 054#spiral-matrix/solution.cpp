class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows, cols, current_row = 0, current_col = 0;
        vector<int> result;
        
        if (matrix.size() == 0)
            return result;
            
        rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        
        for (int start_row = 0, start_col = 0; start_row <= rows/2 && start_col <= cols/2; start_row++, start_col++) {
            
            current_row = start_row;
        
            for (int col = start_col; col <= cols - start_col; col++)
                result.push_back(matrix[current_row][col]);
            
            if (rows - start_row == start_row)
                break;
            
            current_col = cols - start_col;
            
            for (int row = start_row + 1; row <= rows - start_row; row++)
                result.push_back(matrix[row][current_col]);
            
            if (cols - start_col == start_col)
                break;
            
            current_row = rows - start_row;
            
            for (int col = (cols - start_col) - 1; col >= start_col; col--)
                result.push_back(matrix[current_row][col]);
                
            current_col = start_col;
            
            for (int row = (rows - start_row) - 1; row >= start_row + 1; row--)
                result.push_back(matrix[row][current_col]);
        }
        return result;
    }
};