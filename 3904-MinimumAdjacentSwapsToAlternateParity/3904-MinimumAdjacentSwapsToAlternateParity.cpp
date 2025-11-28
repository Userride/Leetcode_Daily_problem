// Last updated: 11/28/2025, 12:48:48 PM
class Solution {
public:
    int minSwaps(vector<int>& a) {
        vector<int> e, o;
        int n = a.size();

        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0)
                e.push_back(i);
            else
                o.push_back(i);
        }

        if (abs((int)e.size() - (int)o.size()) > 1) return -1;

        
        auto calc = [](vector<int>& idxs, int start) {
            int swaps = 0;
            for (int i = 0; i < idxs.size(); ++i)
                swaps += abs(idxs[i] - (start + 2 * i));
            return swaps;
        };

        int res = INT_MAX;
        if (e.size() >= o.size())  
            res = min(res, calc(e, 0));
        if (o.size() >= e.size())  
            res = min(res, calc(o, 0));

        return res;
    }
};
