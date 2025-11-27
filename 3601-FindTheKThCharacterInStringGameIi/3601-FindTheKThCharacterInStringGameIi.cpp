// Last updated: 11/27/2025, 5:15:31 PM
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        char ch = 'a';
        for (int i = 62; i >= 0; --i) {
            long long half = 1LL << i;
            if (k > half) {
                k -= half;
                if (operations[i]) {
                    ch = (ch == 'z') ? 'a' : ch + 1;
                }
            }
        }

        return ch;
    }
};