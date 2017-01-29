class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = low + (high - low)/2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > nums[high]) {
                if (nums[mid] > target && nums[low] <= target)
                    high = mid;
                else
                    low = mid + 1;
            }
            else if (nums[mid] < nums[high]) {
                if (nums[mid] < target && nums[high] >= target)
                    low = mid + 1;
                else
                    high = mid;
            }
            else
                high--;
        }
        return (nums[low] == target) ? true : false;
    }
};