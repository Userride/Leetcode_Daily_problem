// Last updated: 11/28/2025, 12:48:44 PM
class Solution {
public:
    int uniquePaths(vector<vector<int>>& g) {
        int mod = 1e9 + 7;
        int m = g.size();
        int n = g[0].size();
        
        vector<vector<int>> ri(m, vector<int>(n, -1));
        vector<vector<int>> rj(m, vector<int>(n, -1));
        vector<vector<int>> di(m, vector<int>(n, -1));
        vector<vector<int>> dj(m, vector<int>(n, -1));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (j+1 < n) {
                    if (g[i][j+1] == 0) {
                        ri[i][j] = i;
                        rj[i][j] = j+1;
                    } else {
                        ri[i][j] = di[i][j+1];
                        rj[i][j] = dj[i][j+1];
                    }
                }
                
                if (i+1 < m) {
                    if (g[i+1][j] == 0) {
                        di[i][j] = i+1;
                        dj[i][j] = j;
                    } else {
                        di[i][j] = ri[i+1][j];
                        dj[i][j] = rj[i+1][j];
                    }
                }
            }
        }
        
        dp[m-1][n-1] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) {
                    continue;
                }
                if (ri[i][j] != -1) {
                    dp[i][j] = (dp[i][j] + dp[ri[i][j]][rj[i][j]]) % mod;
                }
                if (di[i][j] != -1) {
                    dp[i][j] = (dp[i][j] + dp[di[i][j]][dj[i][j]]) % mod;
                }
            }
        }
        
        return dp[0][0];
    }
};
