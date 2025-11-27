// Last updated: 11/27/2025, 5:17:32 PM
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int current = i;
            count = 0;
            while (current) {
                current = current & (current - 1);
                count++;
            }
            if (count == k) {
                sum += nums[i];
            }
        }
        return sum;
    }
};