class Solution {
public:
    int calculate(string s) {
        long long result = 0, num1 = 0, num2;
        char op;
        istringstream iss('+' + s + '+');
        
        while(iss >> op) {
            if (op == '+' || op == '-') {
                result += num1;
                iss >> num1;
                num1 *= (op == '+') ? 1 : -1;
            } else {
                iss >> num2;
                if (op == '*')
                    num1 *= num2;
                else
                    num1 /= num2;
            }
        }
        
        return result;
    }
};