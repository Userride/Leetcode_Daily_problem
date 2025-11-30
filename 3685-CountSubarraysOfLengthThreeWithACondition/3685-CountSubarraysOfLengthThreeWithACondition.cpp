// Last updated: 11/30/2025, 10:59:13 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        
        for(int i=0;i<n-2;i++){
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]){
                count++;
            }
        }
        return count;
    }
};