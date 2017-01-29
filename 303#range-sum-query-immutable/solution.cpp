class NumArray {
    vector<int> prefix_sum;
public:
    NumArray(vector<int> &nums) {
        int size = nums.size();
        prefix_sum.resize(size);
        for (int i = 0; i < size; i++) {
            prefix_sum[i] = (i == 0) ? nums[i] : nums[i] + prefix_sum[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return (i == 0) ? prefix_sum[j] : prefix_sum[j] - prefix_sum[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);