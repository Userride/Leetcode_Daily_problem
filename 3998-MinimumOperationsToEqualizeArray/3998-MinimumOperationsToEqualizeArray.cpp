// Last updated: 11/28/2025, 12:48:35 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<2) return 0;
        if(nums.size()>=2){
            if(nums[0]==nums[nums.size()-1]) return 0;
        }
        return 1;
    }
};