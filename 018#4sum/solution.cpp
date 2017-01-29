#define DEBUG 0

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(), target1, target2, front, back;
        vector<vector<int> > result;
        vector<int> result_elem(4);
        
        if (nums.size() < 4)
            return result;
            
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            target1 = target - nums[i];
            
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                target2 = target1 - nums[j];
                
                front = j + 1;
                back = n - 1;
                
                while(front < back) {
                    if (DEBUG)
                        cout << "i: " << i << ", j: " << j << ", front: " << front << ", back: " << back << endl;
                    if (nums[front] + nums[back] == target2) {
                        result_elem[0] = nums[i];
                        result_elem[1] = nums[j];
                        result_elem[2] = nums[front];
                        result_elem[3] = nums[back];
                        result.push_back(result_elem);
                        while (front < back && nums[front + 1] == result_elem[2])
                            front++;
                        while (front < back && nums[back - 1] == result_elem[3])
                            back--;
                        front++;
                        back--;
                    } else if (nums[front] + nums[back] < target2) {
                        front++;
                    } else {
                        back--;
                    }
                }
            }
        }
        
        return result;
    }
};