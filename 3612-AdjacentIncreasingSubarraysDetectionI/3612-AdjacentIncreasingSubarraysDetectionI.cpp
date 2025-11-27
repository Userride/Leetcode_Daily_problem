// Last updated: 11/27/2025, 5:15:27 PM

class Solution {
public:
    bool isStrictlyIncreasing(vector<int>& nums, int start, int end) {
        for (int i = start + 1; i < end; i++) {
            if (nums[i - 1] >= nums[i]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int start = 0; start <= n - 2 * k; start++) {
            if (isStrictlyIncreasing(nums, start, start + k) &&
                isStrictlyIncreasing(nums, start + k, start + 2 * k)) {
                return true;
            }
        }
        return false;
    }
};

