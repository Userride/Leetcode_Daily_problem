// Last updated: 11/27/2025, 5:16:11 PM
class Solution {
public:
    bool canAliceWin(vector<int>& nums ){
        int single_digit_sum=0;
        int double_digit_sum=0;
        int total_sum=0;
        //int nums[i]=nums[i]s[i];
        for(int i=0;i<nums.size();i++){
             total_sum= total_sum+nums[i];
            if(nums[i]>=1 && nums[i]<=9){
                single_digit_sum=single_digit_sum+nums[i];
            }
           else if(nums[i]>=9 && nums[i]<=99){
                double_digit_sum=double_digit_sum+nums[i];
           }
        }
        return (single_digit_sum > total_sum/2) || (double_digit_sum >total_sum/2);
    }
};