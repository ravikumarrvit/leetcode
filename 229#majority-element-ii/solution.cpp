#define DEBUG 1

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority1, count1 = 0, majority2, count2 = 0, n = nums.size();
        vector<int> result;
        
        if (n == 0)
            return result;
        
        majority1 = majority2 = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            // The order of conditions are VERY IMPORTANT here
            if (nums[i] == majority1)
                count1++;
            else if (nums[i] == majority2)
                count2++;
            else if (count1 == 0) {
                majority1 = nums[i];
                count1++;
            }
            else if (count2 == 0) {
                majority2 = nums[i];
                count2++;
            }
            else {
                if (count1)
                    count1--;
                if (count2)
                    count2--;
            }
        }
        
        count1 = count2 = 0;
        
        if (DEBUG)
            cout << majority1 <<", " << majority2 << endl;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == majority1)
                count1++;
            if (nums[i] == majority2)
                count2++;
        }
        
        if (count1 > n/3)
            result.push_back(majority1);
        if (count2 > n/3 && majority2 != majority1)
            result.push_back(majority2);
        
        return result;
    }
};