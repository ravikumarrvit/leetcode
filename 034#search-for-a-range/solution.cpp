class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        vector<int> result(2, -1);
        
        while(low <= high) {
            mid = low + (high - low)/2;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
                result[0] = mid;
                break;
            }
            else if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (result[0] == -1)
            return result;
        
        low = 0, high = nums.size()-1;
        
        while(low <= high) {
            mid = low + (high - low)/2;
            if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] != target)) {
                result[1] = mid;
                break;
            }
            else if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return result;
    }
};