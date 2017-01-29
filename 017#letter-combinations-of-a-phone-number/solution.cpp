#define DEBUG 1

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> digit_string_map({
                                                        {2, "abc"}, {3, "def"}, {4, "ghi"},
                                                        {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                                        {8, "tuv"}, {9, "wxyz"}
        });
        vector<string> result, temp_result;
        string digit_string;
        
        for (int i = 0; i < digits.length(); i++) {
            int digit_num = digits[i] - 48;
            digit_string = digit_string_map[digit_num];
            if (DEBUG)
                cout <<"digit_num: " << digit_num << ", digit_string: " << digit_string << endl;
            if (result.size() == 0) {
                for (int j = 0; j < digit_string.length(); j++)
                    result.push_back(digit_string.substr(j, 1));
            } else {
                temp_result.clear();
                temp_result.resize(result.size());
                copy(result.begin(), result.end(), temp_result.begin());
                result.clear();
                if (DEBUG)
                    cout << "reached here" << endl;
                for (string res_str : temp_result) {
                    for (int j = 0; j < digit_string.length(); j++)
                        result.push_back(res_str + digit_string[j]);
                }
            }
        }
        return result;
    }
};