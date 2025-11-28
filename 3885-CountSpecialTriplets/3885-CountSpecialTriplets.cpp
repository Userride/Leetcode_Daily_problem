// Last updated: 11/28/2025, 12:48:50 PM
class Solution {
public:
    int specialTriplets(vector<int>& a) {
        const int M = 1e9 + 7;
        unordered_map<int, int> l, r;
        int n = a.size(), ans = 0;

        for (int x : a) r[x]++;

        for (int j = 0; j < n; ++j) {
            r[a[j]]--;
            int x = a[j] * 2;
            ans = (ans + 1LL * l[x] * r[x] % M) % M;
            l[a[j]]++;
        }

        return ans;
    }
};
