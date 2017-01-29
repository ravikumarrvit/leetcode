class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), max_left = INT_MIN, max_right = INT_MIN; 
        int left = 0, right = n - 1, trapped = 0, trapped_water = 0;
        
        if (!n)
            return 0;
        
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] > max_left)
                    max_left = height[left];
                else
                    trapped_water += max_left - height[left];
                left++;
            } else {
                if (height[right] > max_right)
                    max_right = height[right];
                else
                    trapped_water += max_right - height[right];
                right--;
            }
        }
        
        return trapped_water;
    }
};