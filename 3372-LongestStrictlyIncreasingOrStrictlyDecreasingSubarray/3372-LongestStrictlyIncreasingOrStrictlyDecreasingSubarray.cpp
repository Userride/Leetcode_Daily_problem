// Last updated: 11/27/2025, 5:16:45 PM
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxInc = 1, maxDec = 1;
        int inc = 1, decr = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                decr = 1;  
            } 
            else if (nums[i] < nums[i - 1]) {
                decr++;
                inc = 1;  
            } 
            else {
                inc = 1;
                decr = 1;
            }
            maxInc = max(maxInc, inc);
            maxDec = max(maxDec, decr);
        }
        
        return max(maxInc, maxDec);
    }
};
