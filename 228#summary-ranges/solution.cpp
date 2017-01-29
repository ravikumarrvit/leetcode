class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        string result_elem;
        int n = nums.size(), range_start, range_start_index;;
        
        if (n == 0)
            return result;
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                range_start = nums[i];
                range_start_index = i;
            }
            else if (nums[i] - nums[i - 1] != 1) {
                result_elem.append(to_string(range_start));
                if (i - 1 == range_start_index) {
                    result.push_back(result_elem);
                    result_elem.clear();
                    range_start = nums[i];
                    range_start_index = i;
                    continue;
                }
                result_elem.append("->" + to_string(nums[i - 1]));
                result.push_back(result_elem);
                result_elem.clear();
                range_start = nums[i];
                range_start_index = i;
            }
        }
        if (result_elem.empty()) {
            if (range_start_index != n - 1)
                result.push_back(to_string(range_start) + "->" + to_string(nums[n - 1]));
            else
                result.push_back(to_string(range_start));
        }
            
        return result;
    }
};