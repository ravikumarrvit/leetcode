class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_column = false;
        int m = matrix.size(), n;
        
        if (!m)
            return;
        
        n = matrix[0].size();
        
        if (!n)
            return;
        
        // Index initialization is very important here
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0])
                first_column = true;
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if (!matrix[0][j] || !matrix[i][0])
                    matrix[i][j] = 0;
            }
            if (first_column)
                matrix[i][0] = 0;
        }
    }
};