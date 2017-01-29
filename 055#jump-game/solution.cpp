class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int index = 0, reach = 0;
        if (nums.size() == 1)
            return true;
        while(index < nums.size() && index <= reach) {
            reach = max(index + nums[index], reach);
            index++;
        }
        return index == nums.size();
    }
};