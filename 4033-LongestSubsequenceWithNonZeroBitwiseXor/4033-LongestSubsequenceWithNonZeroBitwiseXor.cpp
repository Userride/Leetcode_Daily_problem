// Last updated: 11/28/2025, 12:48:29 PM
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        bool allZero = true;
        for (int v : nums) {
            total ^= v;
            if (v != 0) allZero = false;
        }
        if (total != 0) return n;
        if (allZero) return 0;
        return n - 1;
    }
};
