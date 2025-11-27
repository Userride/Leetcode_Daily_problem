// Last updated: 11/27/2025, 5:16:29 PM
class Solution {
public:
    string clearDigits(string s) {
        string stack;
        for (char c : s) {
            if (isdigit(c)) {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack;
    }
};