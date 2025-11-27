// Last updated: 11/27/2025, 5:17:22 PM
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX; // Initialize to a large value for tracking minimum sum

        // Iterate over possible 'j' values in the middle of the triplet
        for (int j = 1; j < n - 1; j++) {
            // Find the smallest 'i' where i < j and nums[i] < nums[j]
            int minLeft = INT_MAX;
            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j]) {
                    minLeft = min(minLeft, nums[i]);
                }
            }

            // Find the smallest 'k' where k > j and nums[k] < nums[j]
            int minRight = INT_MAX;
            for (int k = j + 1; k < n; k++) {
                if (nums[k] < nums[j]) {
                    minRight = min(minRight, nums[k]);
                }
            }

            // If both valid i and k are found, compute the sum
            if (minLeft != INT_MAX && minRight != INT_MAX) {
                minSum = min(minSum, minLeft + nums[j] + minRight);
            }
        }

        // If no valid triplet is found, return -1
        return (minSum == INT_MAX) ? -1 : minSum;
    }
};
