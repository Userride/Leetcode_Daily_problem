// Last updated: 11/27/2025, 5:16:21 PM
// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int operations = 0;
        
//         for (int i = 0; i < nums.size(); i++) {
//             int remainder = nums[i] % 3;
//             if (remainder == 1) {
//                 operations += 1;  // Subtract 1 to make it divisible by 3
//             } else if (remainder == 2) {
//                 operations += 1;  // Add 1 to make it divisible by 3
//             }
//         }
        
//         return operations;
//     }
// };

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++) ans+=min(3-(nums[i]%3),nums[i]%3);
        return ans;
    }
};