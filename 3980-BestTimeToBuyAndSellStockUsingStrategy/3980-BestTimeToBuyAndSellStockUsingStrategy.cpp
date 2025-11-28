// Last updated: 11/28/2025, 12:48:38 PM
class Solution {
public:
    long long maxProfit(vector<int>& p, vector<int>& s, int k) {
        int n = p.size();
        long long bp = 0; 
        for (int i = 0; i < n; i++) {
            bp += 1LL * s[i] * p[i];
        }
//ye acha method hai
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) {
            a[i] = -1LL * s[i] * p[i];          
            b[i] = 1LL * p[i] - 1LL * s[i] * p[i]; 
        }

        vector<long long> pa(n+1), pb(n+1);
        for (int i = 0; i < n; i++) {
            pa[i+1] = pa[i] + a[i];
            pb[i+1] = pb[i] + b[i];
        }

        long long d = 0; 
        int h = k/2;
        for (int l = 0; l + k <= n; l++) {
            long long ls = pa[l+h] - pa[l];
            long long rs = pb[l+k] - pb[l+h];
            d = max(d, ls + rs);
        }
//return  bp+d
        return bp + d;
    }
};
