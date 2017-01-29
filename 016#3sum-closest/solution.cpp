#include <algorithm>
#include <limits>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int num, l, h, min = INT_MAX, result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            l = i + 1, h = nums.size() - 1;
            while (l < h) {
                if (abs(target - (nums[i] + nums[l] + nums[h])) < min) {
                    min = abs(target - (nums[i] + nums[l] + nums[h]));
                    result = (nums[i] + nums[l] + nums[h]);
                }
                if ((target - (nums[i] + nums[l] + nums[h])) < 0)
                    h--;
                else
                    l++;
            }
        }
        return result;
    }
};