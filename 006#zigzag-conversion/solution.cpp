class Solution {
public:
    string convert(string s, int numRows) {
        // string result;
        // int index = 0, k;
        // if (numRows <= 1)
        //     return s;
        // for (int i = 0; i < numRows; i++) {
        //     if (i == 0 || i == numRows - 1) {
        //         index = i;
        //         while (index < s.length()) {
        //             result += s[index];
        //             index = index + ((numRows - 2) * 2 + 2);
        //         }
        //     } else {
        //         index = i;
        //         k = 0;
        //         while (index < s.length()) {
        //             result += s[index];
        //             if (k % 2 == 0)
        //                 index = index + ((numRows - (i + 1)) > 1 ?  (numRows - (i + 2))* 2 + 2 : 2);
        //             else
        //                 index = index + ( i > 1 ?  ((i - 1)* 2) + 2 : 2);
        //             k++;
        //         }
        //     }
            
        // }
        // return result;
        string *result = new string[numRows], result_str;
        int result_index = 0, index_change;
        
        if (numRows <= 1)
            return s;
        
        for (int i = 0; i < s.length(); i++) {
            result[result_index].push_back(s[i]);
            if (result_index == 0)
                index_change = 1;
            else if (result_index == numRows - 1)
                index_change = -1;
            result_index += index_change;
        }
        
        for (int i = 0; i < numRows; i++)
            result_str.append(result[i]);
        
        delete[] result;
        
        return result_str;
    }
};