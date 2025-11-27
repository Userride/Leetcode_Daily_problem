// Last updated: 11/27/2025, 5:17:18 PM
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        // Convert nums2 and nums1 to sets for fast lookup
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        // Compute answer1: count how many elements in nums1 exist in nums2
        int answer1 = 0;
        for (int num : nums1) {
            if (set2.count(num)) {
                answer1++;
            }
        }

        // Compute answer2: count how many elements in nums2 exist in nums1
        int answer2 = 0;
        for (int num : nums2) {
            if (set1.count(num)) {
                answer2++;
            }
        }

        // Return the results
        return {answer1, answer2};
    }
};
