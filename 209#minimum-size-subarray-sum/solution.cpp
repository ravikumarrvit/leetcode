class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int index1 = 0, index2 = 0, min_length = INT_MAX, sum = 0;
        
        if (nums.size() == 0)
            return 0;
        
        while(index2 < nums.size()) {
            sum += nums[index2++];
            
            while(sum >= s) {
                min_length = min(min_length, index2 - index1);
                sum -= nums[index1++];
            }
        }
        
        return min_length == INT_MAX ? 0 : min_length;
    }
};