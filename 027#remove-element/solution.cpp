class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length; i++) {
            if (nums[i] == val) {
                if (nums[i] != nums[length - 1]) {
                    swap(nums[i], nums[length - 1]);
                    length--;
                } else {
                    length -= ((length - 1) - i + 1);
                }
            }
        }
        return length;
    }
};