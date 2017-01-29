
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size(), new_length = length;
        
        for (int i = length - 1; i >= 0; i--) {
            if (i > 0 && nums[i] == nums[i-1]) {
                if (i != new_length - 1)
                    swap(nums[i], nums[new_length - 1]);
                new_length--;
            }
        }
        sort(nums.begin(), nums.begin() + new_length);
        return new_length;
    }
};