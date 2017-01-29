class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // int n = nums.size() - 1;
        // for (int i = 0; i <= n; i++) {
        //     if (i == 0 && nums[i] > nums[i + 1] || i == n && nums[i] > nums[i - 1])
        //         return i;
        //     if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        //         return i;
        // }
        // return 0;
        
        int low = 0, mid, high = nums.size() - 1;
        while(low < high) {
            mid = low + (high - low)/2;
            if (nums[mid] > nums[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};