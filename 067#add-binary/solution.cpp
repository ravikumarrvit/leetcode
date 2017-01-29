class Solution {
public:

    void padZeroes(string &str, int lengthToPad) {
        for (int i = 0; i < lengthToPad; i++)
            str = '0' + str;
    }

    string addBinary(string a, string b) {
        int n1 = a.length(), n2 = b.length(), k;
        int sum = 0, carry = 0;
        string result;
        
        if (a.empty())
            return b;
        if (b.empty())
            return a;
        if (n1 > n2)
            padZeroes(b, n1 - n2);
        else if (n2 > n1)
            padZeroes(a, n2 - n1);
        
        k = ((n1 >= n2) ? n1 : n2) - 1;
        
        result.resize(k + 1);
        
        while (k >= 0) {
            sum = carry + (a[k] - '0' + b[k] - '0');
            if (sum == 2) {
                sum = 0;
                carry = 1;
            } else if (sum == 3) {
                sum = 1;
                carry = 1;
            } else {
                carry = 0;
            }
            result[k--] = sum + '0';
        }
        if (carry != 0)
            result = to_string(carry) + result;
        
        return result;
    }
};