// Last updated: 11/28/2025, 12:48:34 PM
class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for (char c : s) {
            int steps = (26 + ('a' - c)) % 26;
            ans = max(ans, steps);
        }
        return ans;
    }
};
