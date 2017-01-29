class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size(), prod_left = 1, prod_right = 1;
        vector<int> result(size, 1);
        
        for (int i = 0; i < size; i++) {
            
            // MULTIPLY by the product of elements on the LEFT
            result[i] *= prod_left;
            prod_left *= nums[i];
            
            // MULTIPLY by the product of elements on the RIGHT
            result[size-1-i] *= prod_right;
            prod_right *= nums[size-1-i];
        }
        
        return result;
    }
};