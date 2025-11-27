// Last updated: 11/27/2025, 5:16:15 PM
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        vector<unordered_map<int, int>> dp(n); 
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1; 
            for (int j = 0; j < i; ++j) {
                int r = (nums[j] + nums[i]) % k;
                if (dp[j].count(r)) {
                    dp[i][r] = max(dp[i][r], dp[j][r] + 1);
                } else {
                    dp[i][r] = max(dp[i][r], 2); 
                }
                ans = max(ans, dp[i][r]);
            }
        }

        return ans;
    }
};
