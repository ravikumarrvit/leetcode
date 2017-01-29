class Solution {
public:
    int numSquares(int n) {
        
        // Can be calculated and used statically
        int min_squares[n + 1];
        
        if (n < 4)
            return n;
            
        fill(min_squares, min_squares + (n + 1), INT_MAX);
            
        min_squares[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++)
                min_squares[i] = min(min_squares[i], min_squares[i - (j * j)] + 1);
        }
        
        return min_squares[n];
    }
};