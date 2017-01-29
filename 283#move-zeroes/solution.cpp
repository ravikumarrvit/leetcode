class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int new_index = 0, index = 0, n = nums.size();
        
        for (int index = 0; index < n; index++) {
            if (nums[index] != 0)
                nums[new_index++] = nums[index];
        }
        
        while (new_index < n)
            nums[new_index++] = 0;
    }
};