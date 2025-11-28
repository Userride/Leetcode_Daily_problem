// Last updated: 11/28/2025, 12:48:57 PM
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        int total = 1 << n; // total number of subsets (2^n)

        for (int mask = 1; mask < total - 1; ++mask) {
            long long prod1 = 1;
            vector<int> subset1, subset2;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    prod1 *= nums[i];
                    if (prod1 > target) break; // early exit
                }
            }

            if (prod1 != target) continue;

            long long prod2 = 1;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    prod2 *= nums[i];
                    if (prod2 > target) break; // early exit
                }
            }

            if (prod2 == target) return true;
        }

        return false;
    }
};
