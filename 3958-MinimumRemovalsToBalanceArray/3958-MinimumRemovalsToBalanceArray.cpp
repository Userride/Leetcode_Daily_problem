// Last updated: 11/28/2025, 12:48:41 PM
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m_l = 1; 
        int l = 0;

        for (int r = 0; r < n; r++) {
            while (nums[r] > (long long)nums[l] * k) {
                l++; 
            }
            m_l = max(m_l, r - l+ 1); 
        }

        return n - m_l; 
    }
};
