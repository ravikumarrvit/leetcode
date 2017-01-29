class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), sum = 0, carry = 0;
        
        if (!n)
            return digits;
        
        for (int i = n - 1; i >= 0; i--) {
            sum = carry + digits[i] + ((i == n - 1) ? 1 : 0);
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        
        if (carry)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};