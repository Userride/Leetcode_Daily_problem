// Last updated: 11/28/2025, 12:48:33 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n; 
        vector<int> valtoremin = nums;

        int a = nums[0];
        int b = nums[1];
        int count = 2; 
        int maxLen = 2;

        for(int i = 2; i < n; i++){
            if(nums[i] == a + b){ 
                count++;      
            } else {
                count = 2;     
            }
            a = b;
            b = nums[i];
            maxLen = max(maxLen, count);
        }
        return maxLen;
    }
};
