// Last updated: 11/29/2025, 4:15:30 PM
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int max_sum=0;
        int max_negative=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                max_negative=max(max_negative,nums[i]);

            } else if(!st.count(nums[i])){
                max_sum=max_sum+nums[i];
                st.insert(nums[i]);
            }
        }
        return max_sum==0 ? max_negative : max_sum;
    }
};