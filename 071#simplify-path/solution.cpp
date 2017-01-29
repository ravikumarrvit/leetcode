#define DEBUG 1

class Solution {
public:
    string simplifyPath(string path) {
        int backslash_index, prev_index = 0;
        string path_component, result;
        deque<string> path_comp_stack;
        
        if (path.empty())
            return "";
        if (path == "/")
            return path;
        while ((backslash_index = path.find("/", prev_index + 1)) != string::npos) {
            path_component = path.substr(prev_index + 1, backslash_index - (prev_index + 1));
            if (path_component == "." || path_component.empty() || (path_component == ".." && path_comp_stack.empty())) {
                prev_index = backslash_index;
                continue;
            }
            else {
                if (path_comp_stack.empty() || path_component != "..") {
                    path_comp_stack.push_back(path_component);
                    if (DEBUG)
                        cout << "path_component: " << path_component << endl;
                }
                else if (path_component == "..")
                    path_comp_stack.pop_back();
                prev_index = backslash_index;
            }
        }
        if (prev_index != path.length() - 1) {
            path_component = path.substr(prev_index + 1, path.length() - (prev_index + 1));
            if (path_component == ".." && !path_comp_stack.empty())
                path_comp_stack.pop_back();
            else if (path_component != "." && path_component != ".." && !path_component.empty()) {
                path_comp_stack.push_back(path_component);
                if (DEBUG)
                    cout << "path_component: " << path_component << endl;
            }
        }
        
        if (path_comp_stack.empty())
            return "/";
        else {
            while (!path_comp_stack.empty()) {
                path_component = path_comp_stack.front();
                path_comp_stack.pop_front();
                result.append("/" + path_component);
            }
        }
        return result;
    }
};