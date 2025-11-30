// Last updated: 11/30/2025, 10:59:11 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count=0;
        int total_sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
       int left_sum=0;
        for(int  i=0;i<n-1;i++){
            left_sum+=nums[i];
           if((left_sum - (total_sum - left_sum)) % 2 == 0)
{
                count++;
            }
        }
        return count;
        
    }
};