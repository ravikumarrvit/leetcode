#define DEBUG 1

class Solution {
public:
    string countAndSay(int n) {
        string init_val = "1", temp_val;
        char prev = '0';
        int count = 0;
        
        if (n == 1)
            return init_val;
        
        for (int i = 1; i < n; i++) {
            count = 0;
            temp_val.clear();
            prev = init_val[0];
            for (int j = 0; j < init_val.length(); j++) {
                if (j == init_val.length() - 1) {
                    if (init_val[j] != prev) {
                        temp_val.append(to_string(count) + prev);
                        count  = 0;
                    }
                    temp_val.append(to_string(count + 1) + init_val[j]);
                    break;
                } else if (init_val[j] != prev) {
                    temp_val.append(to_string(count) + prev);
                    count = 1;
                    prev = init_val[j];
                } else {
                    count++;
                }
            }
            init_val = temp_val;
            if (DEBUG)
                cout << "init_val: " << init_val << endl;
        }
        return init_val;
    }
};