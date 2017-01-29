class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int max_area = INT_MIN, h;
        
        while (start < end) {
            h = min(height[start], height[end]);
            max_area = max(max_area, (end - start) * h);
            while (height[start] <= h && start < end)
                start++;
            while (height[end] <= h && start < end)
                end--;
        }
        
        return max_area;
    }
};