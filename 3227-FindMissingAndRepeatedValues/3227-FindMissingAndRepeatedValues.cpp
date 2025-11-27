// Last updated: 11/27/2025, 5:17:14 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& v) {
        int n = v.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[v[i][j]]++;
            }
        }

        int repeated = -1, missing = -1;

        for (int i = 1; i <= n * n; i++) {
            if (mp[i] == 2) {
                repeated = i;
            } else if (mp[i] == 0) {
                missing = i;
            }
        }

        return {repeated, missing};
    }
};
