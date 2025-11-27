// Last updated: 11/27/2025, 5:16:22 PM
class Solution {
public:
    void flipwindow(vector<int>& nums, int pos) {
        nums[pos] ^= 1;
        nums[pos + 1] ^= 1;
        nums[pos + 2] ^= 1;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operation = 0;

        for (int i = 0; i <= n - 3; i++) { 
            if (nums[i] == 1) 
                continue;
            flipwindow(nums, i);
            operation++;
        }
        if (nums[n - 2] == 0 || nums[n - 1] == 0) 
            return -1;
        
        return operation;
    }
};
