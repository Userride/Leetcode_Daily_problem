// Last updated: 11/30/2025, 11:00:07 PM
class Solution {
public:
    int minElement(vector<int>& nums) {
        int minElement = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int digitSum = 0;
            
            while(num > 0) {
                digitSum += num % 10;
                num /= 10;
            }

            if(digitSum < minElement) {
                minElement = digitSum;
            }
        }
        
        return minElement;
    }
};
