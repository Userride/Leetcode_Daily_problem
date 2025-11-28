// Last updated: 11/28/2025, 12:48:32 PM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            maximum = max(maximum, nums[i]);
            minimum = min(minimum, nums[i]);
        }

        long long result = 1LL * (maximum - minimum) * k;  
        return result;
    }
};
