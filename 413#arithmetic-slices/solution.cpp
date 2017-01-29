class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size(), result = 0;
        vector<int> count(size, 0);
        
        if (size < 3)
            return 0;
        
        count[2] = (A[1] - A[0] == A[2] - A[1]);
        result = count[2];
        
        for (int i = 3; i < size; i++) {
            if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2]))
                count[i] = count[i - 1] + 1;
            result += count[i];
        }
        
        return result;
    }
};