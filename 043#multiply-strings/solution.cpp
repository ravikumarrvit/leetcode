#define DEBUG 0

class Solution {
public:
    string multiply(string num1, string num2) {
        string product(num1.size() + num2.size(), '0');
        int carry, prod, non_zero_index;
        
        if (num1[0] == '0' || num2[0] == '0')
            return "0";
        
        for (int i = num1.size() - 1; i >= 0; i--) {
            carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                prod = carry + ((product[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0'));
                product[i + j + 1] = (prod % 10) + '0';
                carry = prod / 10;
            }
            product[i] = carry + '0';
        }
        non_zero_index = product.find('0');
        if (product[0] != '0')
            return product;
        else if (non_zero_index != string::npos)
            return product.substr(non_zero_index + 1);
        else if (non_zero_index == string::npos)
            return product;
        
        return "0";
    }
};