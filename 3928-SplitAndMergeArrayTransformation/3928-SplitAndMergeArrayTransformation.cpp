// Last updated: 11/28/2025, 12:48:47 PM
class Solution {
public:
    string keyOf(vector<int>& nums){
        string res = "";
        for(int& num : nums){
            res += to_string(num) + '_';
        }
        res.pop_back();
        return res;
    }
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if (nums1 == nums2)
            return 0;

        unordered_map<string, int> seen;
        queue<pair<vector<int>, int>> q;
        q.push({nums1, 0});
        seen[keyOf(nums1)] = 1;

        while (!q.empty()) {
            auto [curr, op] = q.front();
            q.pop();
            for (int l = 0; l < n; l++) {
                for (int r = l; r < n; r++) {
                    
                    vector<int> block(curr.begin() + l, curr.begin() + r + 1);
                    vector<int> rem;
                    rem.insert(rem.end(), curr.begin(), curr.begin() + l);    
                    rem.insert(rem.end(), curr.begin() + r + 1, curr.end());
                    for (int pos = 0; pos <= rem.size(); pos++) {
                        if (pos == l)
                            continue;
                        vector<int> next;
                        next.insert(next.end(), rem.begin(), rem.begin() + pos);
                        next.insert(next.end(), block.begin(), block.end());
                        next.insert(next.end(), rem.begin() + pos, rem.end());

                        if (seen[keyOf(next)] == 0) {
                            if (next == nums2)
                                return op + 1;
                            q.push({next, op + 1});
                            seen[keyOf(next)] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};