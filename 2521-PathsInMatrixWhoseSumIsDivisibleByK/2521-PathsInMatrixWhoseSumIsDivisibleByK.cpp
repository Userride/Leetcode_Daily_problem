// Last updated: 11/27/2025, 5:18:38 PM
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9+7;
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(k, 0));
        dp[0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; ++i) {
            vector<vector<int>> ndp(n, vector<int>(k, 0));
            
            for (int j = 0; j < n; ++j) {

                if (i == 0 && j == 0) {
                    ndp[0][grid[0][0] % k] = 1;
                    continue;
                }

                int val = grid[i][j];

                if (j > 0) {
                    for (int r = 0; r < k; ++r) {
                        if (ndp[j-1][r]) {
                            int nr = (r + val) % k;
                            ndp[j][nr] = (ndp[j][nr] + ndp[j-1][r]) % MOD;
                        }
                    }
                }

                if (i > 0) {
                    for (int r = 0; r < k; ++r) {
                        if (dp[j][r]) {
                            int nr = (r + val) % k;
                            ndp[j][nr] = (ndp[j][nr] + dp[j][r]) % MOD;
                        }
                    }
                }
            }
            
            dp.swap(ndp);
        }
        
        return dp[n-1][0];
    }
};