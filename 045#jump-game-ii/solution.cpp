#define DEBUG 1

class Solution {
public:

    int jump(vector<int>& nums) {
        int max_reach = INT_MIN, current_max = 0;
        int size = nums.size(), steps = 0;
        
        for (int i = 0; i < size - 1; i++) {
            max_reach = max(max_reach, i + nums[i]);
            if (i == current_max) {
                steps++;
                current_max = max_reach;
            }
        }
        
        return steps;
    }

    // int canReachEnd(vector<int>& nums, int index, int n, int &jumps) {
    //     if (index >= n - 1)
    //         return 1;
    //     if (index + nums[index] == index)
    //         return 0;
    //     if (canReachEnd(nums, index + nums[index], n, ++jumps))
    //         return jumps;
    //     else
    //         return 0;
    // }
    
    // int jump(vector<int>& nums) {
    //     int reach = 0, index = 0, n = nums.size(), jumps = INT_MAX;
    //     int last_key, min_jumps, temp = 0;
    //     map<int, int> min_jumps_reach;
        
    //     if (nums.size() == 1)
    //         return 0;
    //     min_jumps_reach[index] = 0;
        
    //     while (index < n && index <= reach) {
    //         temp = 0;
    //         if (min_jumps = canReachEnd(nums, index, n, temp))
    //             jumps = min(min_jumps_reach[index] + min_jumps, jumps);
    //         if (max(index + nums[index], reach) != reach) {
    //             reach = max(index + nums[index], reach);
    //             if (min_jumps_reach.rbegin() != min_jumps_reach.rend())
    //                 last_key = (min_jumps_reach.rbegin())->first;
    //             else
    //                 last_key = 0;
    //             for (int i = last_key + 1; i <= reach; i++)
    //                 min_jumps_reach[i] = min_jumps_reach[index] + 1;
    //         }
    //         index++;
    //     }
    //     return jumps;
    // }
};