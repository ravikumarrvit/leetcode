class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> consec_num_len_map;
        int max_length = INT_MIN, left, right, sum = 0;
        
        for (int num : nums) {
            if (consec_num_len_map[num])
                continue;
                
            left = consec_num_len_map[num - 1];
            right = consec_num_len_map[num + 1];
            sum = left + right + 1;
            
            consec_num_len_map[num] = sum;
            consec_num_len_map[num - left] = consec_num_len_map[num + right] = sum;
            
            max_length = max(max_length, sum);
        }
        
        return max_length;
    }
};