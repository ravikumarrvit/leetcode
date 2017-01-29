class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max = (long long)INT_MIN - 1, sec_max = (long long)INT_MIN - 1, third_max = (long long)INT_MIN - 1;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == max || nums[i] == sec_max || nums[i] == third_max)
                continue;
            if (nums[i] > max) {
                third_max = sec_max;
                sec_max = max;
                max = nums[i];
            } else if (nums[i] > sec_max) {
                third_max = sec_max;
                sec_max = nums[i];
            } else if (nums[i] > third_max) {
                third_max = nums[i];
            }
        }
        
        return (third_max == (long long)INT_MIN - 1) ? (int)max : (int)third_max;
    }
};