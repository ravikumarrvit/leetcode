class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> elem_map;
        
        if (n == 0)
            return false;
            
        for (int i = 0; i < n; i++) {
            if (elem_map[nums[i]])
                return true;
            else
                elem_map[nums[i]] += 1;
        }
        return false;
    }
};