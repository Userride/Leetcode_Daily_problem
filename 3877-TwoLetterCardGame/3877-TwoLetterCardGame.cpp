// Last updated: 11/28/2025, 12:48:51 PM
class Solution {
public:
    int score(vector<string>& cards, char x) {
        unordered_map<char, int> g0;
        unordered_map<char, int> g1;
        int xx = 0;

        for (const string& s : cards) {
            if (s[0] == x && s[1] == x) {
                xx++;
            } else if (s[0] == x) {
                g0[s[1]]++;
            } else if (s[1] == x) {
                g1[s[0]]++;
            }
        }

        int p_internal = 0;
        int l = 0;

        if (!g0.empty()) {
            int n = 0;
            int m = 0;
            for (auto const& [k, v] : g0) {
                n += v;
                if (v > m) {
                    m = v;
                }
            }
            int p0 = (2 * m > n) ? (n - m) : (n / 2);
            p_internal += p0;
            l += n - 2 * p0;
        }

        if (!g1.empty()) {
            int n = 0;
            int m = 0;
            for (auto const& [k, v] : g1) {
                n += v;
                if (v > m) {
                    m = v;
                }
            }
            int p1 = (2 * m > n) ? (n - m) : (n / 2);
            p_internal += p1;
            l += n - 2 * p1;
        }
        
        int p = p_internal;
        
        int pairs_from_l = min(l, xx);
        p += pairs_from_l;
        
        int xx_leftover = xx - pairs_from_l;
        
        int improvement = min(p_internal, xx_leftover / 2);
        p += improvement;

        return p;
    }
};
