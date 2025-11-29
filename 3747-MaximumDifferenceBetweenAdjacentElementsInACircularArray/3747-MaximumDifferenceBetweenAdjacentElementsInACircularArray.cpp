// Last updated: 11/29/2025, 4:15:38 PM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1; // Edge case: If less than 2 elements, return -1

        int maxDiff = INT_MIN; 

        for (int i = 0; i < n; i++) {
            int diff = abs(nums[(i + 1) % n] - nums[i]); // Circular condition
            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};
