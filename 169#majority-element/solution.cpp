class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> elem_count;
        // int half_size = nums.size()/2;
        // for (int num : nums) {
        //     elem_count[num] = elem_count[num] + 1;
        //     if (elem_count[num] && elem_count[num] > half_size)
        //         return num;
        // }
        // return 0;
        
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bitCounts = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCounts++;
                if (bitCounts > n / 2) {
                    major |= mask;
                    break;
                }
            }
        } 
        return major;
    }
};