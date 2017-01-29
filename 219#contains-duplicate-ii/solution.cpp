class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> elem_index;
    
        if (n == 0)
            return false;
        
        for (int i = 0; i < nums.size(); i++) {
            if (elem_index[nums[i]] && (i + 1) - elem_index[nums[i]] <= k )
                return true;
            else
                elem_index[nums[i]] = i + 1;
        }
        return false;
    }
};