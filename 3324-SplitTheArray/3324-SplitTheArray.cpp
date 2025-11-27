// Last updated: 11/27/2025, 5:16:55 PM
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int data[1000]={0};
        int n=nums.size();
        for(int i=0;i<n;i++){
            data[nums[i]]++;
            if(data[nums[i]]>2){
                return false;
            }
        }
        return true;
    }
};