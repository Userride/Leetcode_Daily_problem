// Last updated: 11/27/2025, 5:18:33 PM
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int result = 0;

        
        if (n % 2 != 0) {
            for (int i = 0; i < m; i++) {
                result ^= nums1[i];
            }
        }

       
        if (m % 2 != 0) {
            for (int j = 0; j < n; j++) {
                result ^= nums2[j];
            }
        }

        return result;
    }
};
