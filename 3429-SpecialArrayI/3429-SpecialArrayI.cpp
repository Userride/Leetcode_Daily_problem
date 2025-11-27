// Last updated: 11/27/2025, 5:16:37 PM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                return false;
            }
        }
        return true;
    }
};