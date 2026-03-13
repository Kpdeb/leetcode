class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string temp;
        
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (temp == "..") {
                    if (!stk.empty()) stk.pop_back();
                } 
                else if (!temp.empty() && temp != ".") {
                    stk.push_back(temp);
                }
                temp.clear();
            } else {
                temp += path[i];
            }
        }
        
        string result = "/";
        for (int i = 0; i < stk.size(); i++) {
            result += stk[i];
            if (i < stk.size() - 1) result += "/";
        }
        
        return result;
    }
};
