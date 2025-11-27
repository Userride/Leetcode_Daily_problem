// Last updated: 11/27/2025, 5:16:17 PM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
      int n=nums.size();
      int evencount=0;
      int oddcount=0;
      for(int i=0;i<n;i++){
        if(nums[i]%2==0){
          evencount++;
        }else{
          oddcount++;
        }

      }
      int alternatingcount=1;
      int parity=nums[0]%2;
      for(int i=0;i<n;i++){
        int currentparity=nums[i]%2;
        if(parity!=currentparity){
          alternatingcount++;
          parity=currentparity;
        }

      }
        return max({evencount,oddcount,alternatingcount});
    }
};