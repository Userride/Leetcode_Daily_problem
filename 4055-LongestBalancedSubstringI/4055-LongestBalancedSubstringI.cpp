// Last updated: 11/28/2025, 12:48:23 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        string pireltonak = s;
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int first = 0, ok = 1;
                for (int f : freq) {
                    if (f > 0) {
                        if (first == 0) first = f;
                        else if (f != first) { ok = 0; break; }
                    }
                }
                if (ok) maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};
