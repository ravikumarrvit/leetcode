class Solution {
public:

    void combination_sum3_recurse(vector<vector<int>> &result, vector<int> &result_elem, int k,
                                    int remainder, int start_value) {
        if (result_elem.size() > k)
            return;
        else if (result_elem.size() == k && remainder == 0)
            result.push_back(result_elem);
        else {
            for (int i = start_value; i <= 9; i++) {
                result_elem.push_back(i);
                combination_sum3_recurse(result, result_elem, k, remainder - i, i + 1);
                result_elem.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> result_elem;
        
        combination_sum3_recurse(result, result_elem, k, n, 1);
        
        return result;
    }
};