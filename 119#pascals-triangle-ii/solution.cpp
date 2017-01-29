class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result, prev;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    result.push_back(1);
                else
                    result.push_back(prev[j - 1] + prev[j]);
            }
            prev.clear();
            prev.resize(result.size());
            copy(result.begin(), result.end(), prev.begin());
            if (i != rowIndex)
                result.clear();
        }
        return result;
    }
};