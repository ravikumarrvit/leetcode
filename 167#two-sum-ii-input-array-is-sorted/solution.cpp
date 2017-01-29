class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pointer1 = 0, pointer2, n = numbers.size();
        vector<int> result;
        
        if (n == 0)
            return result;
        
        pointer2 = n - 1;
        
        while(pointer1 < pointer2) {
            if (numbers[pointer1] + numbers[pointer2] == target) {
                result.push_back(pointer1 + 1);
                result.push_back(pointer2 + 1);
                return result;
            }
            else if (numbers[pointer1] + numbers[pointer2] > target)
                pointer2--;
            else
                pointer1++;
        }
        
        return result;
    }
};