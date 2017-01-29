class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > spiral(n, vector<int>(n));
        int k = 1, row = 0, col = 0, i = 0, j = 0;
        
        if (!n)
            return spiral;
        
        while (k <= n * n) {
            row = i;
            col = j;
            
            while (col < n - j)
                spiral[row][col++] = k++;
            
            row = i + 1;
            col = n - j - 1;
            
            while (row < n - i)
                spiral[row++][col] = k++;
            
            row = n - i - 1;
            col = n - j - 2;
            
            while (col > j)
                spiral[row][col--] = k++;
            
            row = n - i - 1;
            col = j;
            
            while (row > i)
                spiral[row--][col] = k++;
            
            i++;
            j++;
        }
        
        return spiral;
    }
};