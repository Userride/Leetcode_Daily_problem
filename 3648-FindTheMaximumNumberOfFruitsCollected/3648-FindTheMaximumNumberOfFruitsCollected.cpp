// Last updated: 12/1/2025, 12:52:00 PM
class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int solve(int i, int p, vector<vector<int>>& fruits) {
        if (p == i)
            return 0;
        if (i == n - 2)
            return fruits[p][i];
        if (dp[i][p] != -1)
            return dp[i][p];

        int maxi = 0;

        for (int j = -1; j <= 1; j++) {
            int newP = p - j;
            if (newP > i && newP < n) {
                int a = solve(i + 1, newP, fruits);
                maxi = max(maxi, a);
            }
        }

        return dp[i][p] = fruits[p][i] + maxi;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        dp.assign(n, vector<int>(n, -1));

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += fruits[i][i];
        }

        sum += solve(0, n - 1, fruits);

        dp.assign(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(fruits[i][j], fruits[j][i]);
            }
        }

        sum += solve(0, n - 1, fruits);

        return sum;
    }
};