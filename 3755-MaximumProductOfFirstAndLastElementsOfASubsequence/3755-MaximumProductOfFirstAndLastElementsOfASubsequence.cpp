// Last updated: 11/29/2025, 4:15:34 PM

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int k = m - 1;
        int n = nums.size();
        if (n == 0) 
            return 0;

        vector<long long> prefix_max(n);
        vector<long long> prefix_min(n);
        prefix_max[0] = nums[0];
        prefix_min[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i-1], static_cast<long long>(nums[i]));
            prefix_min[i] = min(prefix_min[i-1], static_cast<long long>(nums[i]));
        }

        long long res = LLONG_MIN;
        for (int j = k; j < n; j++) {
            int i_index = j - k;
            long long cand1 = prefix_max[i_index] * static_cast<long long>(nums[j]);
            long long cand2 = prefix_min[i_index] * static_cast<long long>(nums[j]);
            if (cand1 > res) res = cand1;
            if (cand2 > res) res = cand2;
        }

        return res;
    }
};