// Last updated: 11/27/2025, 5:16:40 PM
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> same_parity(n - 1, 0);
        vector<int> prefix_sum(n, 0);
        
        // Step 1: Compute the same_parity array
        for (int i = 0; i < n - 1; ++i) {
            if ((nums[i] % 2) == (nums[i + 1] % 2)) {
                same_parity[i] = 1;
            }
        }
        
        // Step 2: Compute prefix_sum of same_parity
        for (int i = 0; i < n - 1; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + same_parity[i];
        }
        
        // Step 3: Process queries
        vector<bool> answer;
        for (const auto& query : queries) {
            int from_i = query[0];
            int to_i = query[1];
            
            // Check range in prefix_sum
            int range_sum = prefix_sum[to_i] - prefix_sum[from_i];
            answer.push_back(range_sum == 0); // True if no same_parity pairs
        }
        
        return answer;
    }
};
