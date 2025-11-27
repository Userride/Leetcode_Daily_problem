// Last updated: 11/27/2025, 5:18:08 PM
// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         int n = nums.size();
//         long long count = 0;  
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper) {
//                     count++;
//                 }
//             }
//         }
        
//         return count;
//     }
// };
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; i++) {
            int left = lower - nums[i];
            int right = upper - nums[i];

            int l = lower_bound(nums.begin() + i + 1, nums.end(), left) - nums.begin();
            int r = upper_bound(nums.begin() + i + 1, nums.end(), right) - nums.begin();

            count += (r - l);
        }

        return count;
    }
};