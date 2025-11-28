// Last updated: 11/28/2025, 12:48:26 PM
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n=nums.size();
        int evensum=0;
        int oddsum=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                evensum=evensum+nums[i];
            }else{
                oddsum=oddsum+nums[i];
            }
        }
        return evensum-oddsum;
    }
};  