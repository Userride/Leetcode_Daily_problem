// Last updated: 11/27/2025, 5:16:14 PM
class Solution {
public:
    int maxOperations(string s) {
        int result = 0;
        int count = 0;
        int n = s.size();
        bool flag = true;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && flag) {
                result += count;
                flag = false;
            } 
            else if (s[i] == '1') {
                count++;
                flag = true;
            }
        }
        return result;
    }
};