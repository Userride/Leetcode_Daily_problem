// Last updated: 11/27/2025, 5:16:58 PM
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int pre_scr=-1;
        int ans=1;
      for(int i=0;i<nums.size()-1;i+=2)
      {
            int s=nums[i]+nums[i+1];
            if(pre_scr==-1)pre_scr=s;
            else{
                if(pre_scr==s){
ans++;


                }
                else{
                    return ans;
                }
            }
      }  
      return ans;
    }
};