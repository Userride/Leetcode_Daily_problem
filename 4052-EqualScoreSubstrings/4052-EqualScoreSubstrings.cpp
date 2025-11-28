// Last updated: 11/28/2025, 12:48:22 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        vector<int>result(n);
        for (int i = 0; i < n; i++) {
            result[i] = s[i] - 'a' + 1;
        }
        for (int i = 0; i < n - 1; i++) {
            int leftSum = 0, rightSum = 0;
            
            for (int j = 0; j <= i; j++) {
                leftSum = leftSum +result[j];
            }
            for (int j = i + 1; j < n; j++) {
                rightSum = rightSum +result[j];
            }
            if (leftSum == rightSum)
                return true;
        }
        return false;
    }
};
