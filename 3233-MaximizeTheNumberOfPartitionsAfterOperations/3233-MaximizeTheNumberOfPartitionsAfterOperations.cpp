// Last updated: 11/27/2025, 5:17:12 PM
class Solution {
public:
    unordered_map<long long, int> memo;

    int dfs(int i, string& s, int usedMask, bool canChange, int k) {
        if (i == s.size()) return 0;
        long long key = ((long long)i << 27) | ((long long)usedMask << 1) | (canChange ? 1LL : 0LL);
        if (memo.count(key)) return memo[key];

        int currBit = 1 << (s[i] - 'a');
        int nextMask = usedMask | currBit;
        int res;

        // Option 1: Keep current character
        if (__builtin_popcount(nextMask) > k)
            res = 1 + dfs(i + 1, s, currBit, canChange, k);
        else
            res = dfs(i + 1, s, nextMask, canChange, k);

        // Option 2: Change current character (if allowed)
        if (canChange) {
            for (int c = 0; c < 26; ++c) {
                int altBit = 1 << c;
                int altMask = usedMask | altBit;
                int temp;
                if (__builtin_popcount(altMask) > k)
                    temp = 1 + dfs(i + 1, s, altBit, false, k);
                else
                    temp = dfs(i + 1, s, altMask, false, k);
                res = max(res, temp);
            }
        }

        return memo[key] = res;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        return 1 + dfs(0, s, 0, true, k);
    }
};
