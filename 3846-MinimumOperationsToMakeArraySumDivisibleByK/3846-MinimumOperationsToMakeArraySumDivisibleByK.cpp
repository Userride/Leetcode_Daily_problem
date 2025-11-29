// Last updated: 11/29/2025, 4:15:20 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int rem = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
            rem = sum % k;
           
        }
         if (rem == 0) {
                return 0;
            }
        return rem;
    }
};