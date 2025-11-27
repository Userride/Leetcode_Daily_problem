// Last updated: 11/27/2025, 5:18:18 PM
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
       unordered_map<int,int>fr;
        int r,mx=0;
       for(int x:nums) {
          r=((x%value)+value)%value;
          fr[r]++;
       }
       while(true){
            r=mx%value;
            if(fr[r]>0)
              fr[r]--;
            else break;
            mx++;
        }
        return mx; 
    }
};