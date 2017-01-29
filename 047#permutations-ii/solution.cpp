class Solution {
public:
    void backtrack_permutation(vector<vector<int>> &result, vector<int> &result_element, 
                                vector<int> &nums, vector<bool > &element_used) {
        if (result_element.size() == nums.size())
            result.push_back(result_element);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (element_used[i] || (i > 0 && nums[i - 1] == nums[i] && !element_used[i - 1]))
                    continue;
                element_used[i] = true;
                result_element.push_back(nums[i]);
                backtrack_permutation(result, result_element, nums, element_used);
                result_element.pop_back();
                element_used[i] = false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> result_element;
        vector<bool> element_used(nums.size(), false);
        
        sort(nums.begin(), nums.end());
        backtrack_permutation(result, result_element, nums, element_used);
        
        return result;
    }
};