class Solution {
public:
    int myAtoi(string str) {
        int index = 0, converted_num = 0, sign = 1;
        
        while(str[index] == ' ')
            index++;
        
        if (str[index] == '+' || str[index] == '-')
            sign = (str[index++] == '+') ? 1 : -1;
        
        while(str[index] >= '0' && str[index] <= '9') {
            if (converted_num > INT_MAX/10 || (converted_num == INT_MAX/10 && str[index] > '7'))
                return (sign == 1) ? INT_MAX : INT_MIN;
            converted_num = (converted_num * 10) + str[index++] - '0';
        }
        
        return sign * converted_num;
    }
};