#define DEBUG 0

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), front, back, index = 0;
        
        if (n < 2)
            return;
        
        front = 0, back = n - 1;
        
        // for (int i = 1; i < n; i++) {
        //     while (nums[i] == 0 && i > front)
        //         swap(nums[i], nums[front++]);
        // }
        
        // for (int i = front; i < n; i++) {
        //     while (nums[i] == 2 && i < back)
        //         swap(nums[i], nums[back--]);
        // }
        
        for (int i = 0; i < n; i++) {
            
            // The order of check is very important as we have to check for element value 2 before element value 0
            while (nums[i] == 2 && i < back)
                swap(nums[i], nums[back--]);
            
            while (nums[i] == 0 && i > front)
                swap(nums[i], nums[front++]);
        }
    }
};