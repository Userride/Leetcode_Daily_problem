// Last updated: 11/27/2025, 5:18:25 PM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        int count2=0;
        
        for(int i=0;i<n;i++){
          if(nums[i]>0){
            count1++;
          }
          else if(nums[i]<0){
            count2++;
          }
       
        }
        return max(count1,count2);
    }
};