class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;
        
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (curr == "..") {
                    if (!stack.empty()) stack.pop_back();
                } else if (!curr.empty() && curr != ".") {
                    stack.push_back(curr);
                }
                curr.clear();
            } else {
                curr += path[i];
            }
        }
        
        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i != stack.size() - 1) result += "/";
        }
        
        return result;
    }
};