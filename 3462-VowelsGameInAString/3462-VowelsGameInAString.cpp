// Last updated: 11/27/2025, 5:16:23 PM
class Solution {
public:
    bool doesAliceWin(string s) {
        return count_if(s.begin(), s.end(), [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';});
    }
};