class Solution {
public:

    void combinationSumRecurse(vector<int>& candidates, int remainder, int start_index,
                                vector<vector<int> > &result, vector<int> result_elem) {
        if (remainder == 0) {
            result.push_back(result_elem);
            return;
        } else if (remainder < 0) {
            return;
        }
        
        for (int i = start_index; i < candidates.size(); i++) {
            result_elem.push_back(candidates[i]);
            combinationSumRecurse(candidates, remainder - candidates[i], i, result, result_elem);
            result_elem.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> result_elem;
        
        if (!candidates.size())
            return result;
        
        combinationSumRecurse(candidates, target, 0, result, result_elem);
        
        return result;
    }
};