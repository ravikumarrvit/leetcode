#define DEBUG 0

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int min_sum = 0;
        
        if (triangle.size() == 0)
            return min_sum;
        
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0)
                    triangle[i][j] += triangle[i - 1][j];
                else if (j == triangle[i].size() - 1)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                    triangle[i][j] += (triangle[i - 1][j - 1] <= triangle[i - 1][j]) ? triangle[i - 1][j - 1]: triangle[i - 1][j];
            }
        }
        min_sum = *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
        
        return min_sum;
    }
};