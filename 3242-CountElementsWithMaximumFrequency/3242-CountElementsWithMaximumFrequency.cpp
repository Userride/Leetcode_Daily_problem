// Last updated: 11/27/2025, 5:17:09 PM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int maxfreq=0;
        for(auto & it:mp){
            maxfreq= max(maxfreq,it.second);
           
        }
        int total=0;
        for(auto & it:mp){
            if(maxfreq==it.second){
                total=total+it.second;
            }
        }
        return total;
    }
};