class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> result_element;
        
        sort(nums.begin(), nums.end());
        subsets_backtrack(result, result_element, nums, 0);
        
        return result;
    }
    
    void subsets_backtrack(vector<vector<int>> &result, vector<int> result_element, vector<int> &nums, int start_index) {
        result.push_back(result_element);
        for (int i = start_index; i < nums.size(); i++) {
            result_element.push_back(nums[i]);
            subsets_backtrack(result, result_element, nums, i + 1);
            result_element.pop_back();
        }
    }
};